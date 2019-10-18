#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    bool *visited;

    void topologicalSortRecur(int v,stack<int> &st);

    public:
        Graph(int V);
        void addEdge(int s, int d);
        void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];

    visited = new bool[V];
    memset(visited,false,sizeof(visited));
    
}

void Graph::addEdge(int s, int d){
    adj[s].push_back(d);
}

void Graph::topologicalSortRecur(int v,stack<int> &st){
    visited[v] = true;

    list<int>::iterator it;            

    for(it = adj[v].begin();it != adj[v].end();it++){
        if(!visited[*it])
            topologicalSortRecur(*it,st);
    }
    st.push(v);
}

void Graph::topologicalSort(){
    stack<int> st;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            topologicalSortRecur(i,st);
        }
    }
    while(!st.empty()){
        cout<<char(st.top()+'a')<<" ";
        st.pop();
    }
}

void alien_dictionary(string dict[], int N, int k){
    Graph g(k);

    for(int i=0;i<N-1;i++){
        string word1 = dict[i],word2 = dict[i+1];
        for(int j=0; j<min(word1.length(),word2.length()); j++){
            if(word1[j]!=word2[j]){
                g.addEdge(word1[j]-'a',word2[j]-'a');
                break;
            }
        }
    }

    g.topologicalSort();

}

// Driver program to test above functions 
int main() 
{ 
    string words[] = {"baa", "abcd", "abca", "cab", "cad"}; 
    alien_dictionary(words, 5, 4); 
    return 0; 
} 

