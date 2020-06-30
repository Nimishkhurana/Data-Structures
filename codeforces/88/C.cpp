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
    
    int T;
    cin>>T;
    while(T--){
        int i, j;
        int h, c, t;
        cin>>h>>c>>t;
        if(t == h){
            cout<<1<<"\n";
        }
        else if(t <= (h + c)/2){
            cout<<2<<"\n";
        }
        else{
            int r = 1e6, l = 3, cnt = 0;
            while(l < r){
                int mid = (l + r)/2;
                if(mid%2==0) mid++;
                double temp = (double)(h*(mid+1)/2 + c*(mid/2))/mid;
                
            }
        }
    }
   
    return 0;
}