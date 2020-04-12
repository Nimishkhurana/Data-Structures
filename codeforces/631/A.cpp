#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

bool comparator1(pair<int,int>p1, pair<int,int> p2){
    return p1.first > p2.first;
}

int main(){
    fast 
    int T;
    T = 1;
    while(T--){
        int i, j, n, m;
        cin>>n>>m;
        pair<int,int> l[m];
        int s=0;
        rep(i,0,m){
            cin>>l[i].first;
            l[i].second = i;
            s += l[i].first;
        }

        if(s<n || s>=2*n){
            cout<<"-1\n";
            continue;
        }
        

        sort(l, l+m, comparator1);

        int res[m];
        int curr = 1;

        // cout<<"h";
        rep(i,0,m){
            int ind = l[i].second;
            cout<<l[i].first<<" ";
            if(curr + l[i].first <= n){
                res[ind] = curr;
                curr += l[i].first;
            }
            else break;       
        }

        // cout<<"h";

        curr = 0;
        rep(j, i, m){
            res[j] = res[curr]+1;
            curr++;
        }

        // cout<<"h";

        rep(i,0,m) cout<<res[i]<<" \n"[i==m-1];
    }
    return 0;
}