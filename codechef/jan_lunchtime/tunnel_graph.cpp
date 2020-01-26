#include<bits/stdc++.h>
using namespace std;

// typedef "push_back" pb;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cin.ignore();
        vector<int> g[n];

        string s;
        bool flag = false;
        for(int i=0;i<n;i++){
            
            cin>>s;
            if(i==n-1 && s[n-1]!='1') 
                flag = true;
            for(int j = max(0, i-k); j<min(i+k+1, n) ;j++){
                if(s[j] == '1' && j!=i)
                    g[i].push_back(j);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j: g[i])
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        if(flag){
            cout<<-1<<endl;
            continue;
        }
            
        // cout<<"tree made";

        queue<int> q;
        vector<int> distance(n,0);
        vector<bool> vis(n,false);
        q.push(0);
        vis[0] = true;
        distance[0] = 0;
        int minJumps = 0;
        bool flag2 = false;
        while (!q.empty() && flag2==false){
            // cout<<q.size()<<"  ";
            for(int i=0;i<q.size();i++){
                int u = q.front();
                // cout<<"u "<< u<<" ";
                q.pop();

                for(int v: g[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                        distance[v] = distance[u]+1;

                        if(v == n-1){
                            flag2 = true;
                            // break;
                        }
                    }       
                }
            }
            
            // cout<<"  "<<minJumps<<endl; 
        }
        if(!flag2)
            cout<<-1<<endl;
        else
            cout<<distance[n-1]<<endl;
        

    }
    return 0;
    
}