// Game playing, Trie
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>

const int MAX = 1e6;
const int alpha = 26;
int trie[MAX][alpha];
bool win[MAX], lose[MAX]; //win[i] means player can win by move at this step
int root;
int sz;
int n,k;


int getNode(){
    return ++sz;
}

void addTrie(string s){
    int len = s.length();

    int v = root;
    // cout<<root;
    for(int i=0;i<len;i++){
        int ch = s[i] - 'a';
       // cout<<ch<<" ";
        if(trie[v][ch]==0) 
            trie[v][ch] = getNode();
        //cout<<trie[v][ch]<<" ";
        v = trie[v][ch];
    }
}

void dfs(int v){
    win[v] = false;
    lose[v] = false;
    bool isLeaf = true;
    for(int ch=0;ch<alpha;ch++){
        int child = trie[v][ch];
        if(child){
            isLeaf = false;
            dfs(child);

            win[v] |= !win[child];
            lose[v] |= !lose[child];
        }
    }
    if(isLeaf)
        lose[v] = true;
}

void printAns(bool win, bool lose){
    // cout<<win<<" "<<lose<<endl;
    if(!win)
        cout<<"Second\n";
    else if(lose)
        cout<<"First\n";
    else if(k%2)
        cout<<"First\n";
    else
        cout<<"Second\n";
}
int main(){
    
    cin>>n>>k;
    root = getNode();
    string s;
   
    while(n--){
        cin>>s;
        addTrie(s);
    }
    // for(int i=0;i<=sz;i++){
    //     for(int ch=0;ch<alpha;ch++){
    //         cout<<trie[sz][ch]<<" ";
            
    //     }
    //     cout<<endl;
    // }
    // cout<<"1.";

    dfs(root);
    // cout<<"2.";
    printAns(win[root], lose[root]);

    return 0;
}
