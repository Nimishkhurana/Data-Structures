//Author: nimishkhurana
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umapi unordered_map<int,int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int> 
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define mk make_pair
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int i, j;
    int n, k, diameter;
    vector<pii> edges;

    cin>>n>>diameter>>k;
    
    if(diameter > n - 1 || (k == 1 && n > 2)){
        cout<<"NO\n";
        return 0;
    }
    vector<int> degree(n, 0);
    set<pii> q;
    for(int i = 0; i < diameter; i++){
        degree[i]++;
        degree[i+1]++;
        edges.pb({i, i+1});
        q.insert({max(i, diameter - i), i});
    }
    q.insert({diameter, diameter});

    for(int i = diameter + 1; i < n; i++){
        while(!q.empty() && (q.begin()->first == diameter || degree[q.begin()->second] >= k)) q.erase(q.begin());

        if(q.empty()){
            cout<<"NO\n";
            return 0;
        }

        int u = q.begin()->second, distu = q.begin()->first;
        degree[i]++;
        degree[u]++;

        edges.pb({i, u});
        
        q.insert({distu+1, i});
    }

    cerr<<edges.size();
    if((int)edges.size() < n-1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        for(auto edge: edges){
            cout<<edge.first+1<<" "<<edge.second+1<<"\n";
        }
    }
   
    return 0;
}