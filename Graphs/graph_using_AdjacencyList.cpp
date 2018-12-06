#include<iostream>
using namespace std;

struct nodeS{
    int info;
    nodeS *link;
}*top = NULL;

nodeS* getNode(int);
void push(int );
int pop();

nodeS* getNode(int data){
    nodeS *N = new nodeS();
    N->info = data;
    N->link = NULL;
    return N;
}


void push(int data){
    nodeS *N = getNode(data);
    if(top == NULL)
        top = N;
    else{
        N->link = top;
        top = N;
    }
}

int pop(){
    if(top==NULL){
       cout<<"Stack Underflow\n";
        return NULL;
       }
    else{
         nodeS *temp = top;
        if(top->link==NULL)
            top = NULL;
        else
            top = top->link;

        delete top;
        return temp->info;
    }
}

bool isSEmpty(){
    if(top==NULL)
        return true;
    else
        return false;
}

struct nodeQ{
    int info;
    nodeQ *link;
}*Front,*Rear = NULL;

nodeQ* getnodeQ(int );
void Qinsert(int );
int Qdelete();


nodeQ* getnodeQ(int data){
    nodeQ *N = new nodeQ();
    N->info = data;
    N->link = NULL;
    return N;
}

void Qinsert(int data){
    nodeQ *N = getnodeQ(data);
    if(Front == NULL)
        Front = Rear = N;
    else{
        Rear->link = N;
        Rear = N;
    }
}

int Qdelete(){
    int data;
    if(Front==NULL){
       cout<<"Queue Underflow\n";
       return ' ';
       }
    else{
         nodeQ *temp = Front;
         data = Front->info;
        if(Front == Rear)
            Front = Rear = NULL;
        else
            Front = Front->link;
        delete temp;
        return data;
    }
}

bool isQEmpty(){
    if(Front==NULL)
        return true;
    else
        return false;
}


struct node{
    int vertex;
    node* link;
};

class Graph{
    int n;
    node** vertices;

    node * findVertex(int );
    node * getNode(int);
    void insertEnd(node** ,node *);
    void traverseList(node* );
    void DFSUtil(int,bool[]);
public:
    Graph();
    void addEdge(int,int);
    void displayGraph();
    void BFS(int);
    void DFS(int);
    void DFS2(int);


};

Graph::Graph(){
    cout<<"Enter number of vertices in graph: ";
    cin>>n;
    vertices = new node*[n];
    for(int i=0;i<n;i++){
        vertices[i] = getNode(i);
    }
}

node* Graph:: getNode(int data){
    node *temp = new node;
    temp->vertex = data;
    temp->link = NULL;
    return temp;
}
//Function to traverse the adjacency list of a vertex
void Graph:: insertEnd(node** head,node *N){
    node *temp = *head;
    if(temp == NULL)
        temp = N;
    while(temp->link){
        temp = temp->link;
    }
    cout<<"\nEdge added\n";
    temp->link = N;

}

void Graph:: addEdge(int source,int destination){
    if(source >= n || destination >= n){
        cout<<"Vertex not found in graph\n";
        return;
    }
    node *temp = getNode(destination);
    node **v = vertices + source;
    insertEnd(v,temp);
}

node *Graph:: findVertex(int v){
    for(int i=0;i<n;i++)
        if( vertices[i]->vertex == v )
            return vertices[i];
}


void Graph:: displayGraph(){
    cout<<"Adjancy List of Graph:-\n\n";
    for(int i=0;i<n;i++){
        cout<<i<<": ";
        traverseList(vertices[i]);
        cout<<endl;
    }
}

void Graph:: traverseList(node* head){
    if(head->link == NULL)
        return;
    node *temp = head->link;
    while(temp){
        cout<<temp->vertex<<"->";
        temp = temp->link;
    }
}

void Graph::BFS(int v){
    bool isVisited[n];
    for(int i=0;i<n;i++)
        isVisited[i] = false;
    Qinsert(v);
    isVisited[v] = true;
    while(isQEmpty() == false){
        int current = Qdelete();
        cout<<current<<" ";
        if(vertices[current]->link){
            node *temp = vertices[current]->link;
            while(temp){
                int a = temp->vertex;
                if(isVisited[a] == false){
                    Qinsert(a);
                    isVisited[a] == true;
                }
                temp = temp->link;
            }
        }
    }
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    if(vertices[v]->link){
            node *temp = vertices[v]->link;
            while(temp){
                int a = temp->vertex;
                if(visited[a] == false)
                    DFSUtil(a,visited);
                temp = temp->link;
            }
        }
    cout << v << " ";
}

void Graph::DFS(int v)
{
    bool isVisited[n];
    for (int i = 0; i < n; i++)
        isVisited[i] = false;
    DFSUtil(v, isVisited);
}

void Graph::DFS2(int v){
    bool isVisited[n];
    for(int i=0;i<n;i++)
        isVisited[i] = false;
    push(v);
    isVisited[v] = true;
    while(isSEmpty() == false){
        int current = pop();
        cout<<current<<" ";
        if(vertices[current]->link){
            node *temp = vertices[current]->link;
            while(temp){
                int a = temp->vertex;
                if(isVisited[a] == false){
                    push(a);
                    isVisited[a] == true;
                }
                temp = temp->link;
            }
        }
    }
}


int main(){
    int ch;
    int s,d,v;
    Graph graph;
    do{
        cout<<"\n1.Add Edge\n2.Display Adjacency List of Graph\n3.BFS\n4.DFS\n0.Exit\n\nEnter your choice: ";
        cin>>ch;
        switch(ch){
    case 1:
        cout<<"Enter Source and Destination of Edge\n";
        cout<<"Source: ";
        cin>>s;
        cout<<"Destination: ";
        cin>>d;
        graph.addEdge(s,d);
        break;
    case 2:
        graph.displayGraph();
        break;
    case 3:
        cout<<"Enter vertex from where to start BFS: ";
        cin>>v;
        graph.BFS(v);
        break;
    case 4:
        cout<<"Enter vertex from where to start DFS: ";
        cin>>v;
        graph.DFS2(v);
        break;
        }
    }while(ch!=0);
}
