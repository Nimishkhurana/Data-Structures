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

int main(){
    fast 
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int i, a[n];
        int vis[n] = {0};
        int l1 = 0, l2 = 0;
        rep(i,0,n){
            cin>>a[i];
            vis[a[i]]++;
            if(vis[a[i]]==2){
                l1 = max(l1, a[i]);
            }
        }

        l2 = n-l1;
        // cout<<l1<<" "<<l2<<"\n";

        if(l1==0 || l2==0){
            cout<<"0\n";
            continue;
        }

        int j, res = 0;
        vector<pair<int, int> > ans;
        int p[l1], p2[l2];
        bool f1 = 1, f2 = 1;
        rep(i,0,l1){
            p[i] = a[i];  
        }

        sort(p, p+l1);

        rep(i,0,l1){
            if(p[i]!=i+1){
                f1 = false;
            }
        }

        rep(j, l1, n)
            p2[j-l1] = a[j];
        
        sort(p2, p2+l2);
        
        rep(j,0,l2){
            if(p2[j]!=j+1){
                f2 = false;
            }
        }

        if(f1 && f2){
            res++;
            ans.pb(mk(l1, l2));
        }
        
        f1 = 1, f2 = 1;
        rep(i,0,l2){
            p2[i] = a[i];  
        }

        sort(p2, p2+l2);

        rep(i,0,l2){
            if(p2[i]!=i+1){
                f1 = 0;
            }       
        }

        rep(j, l2, n)
            p[j-l2] = a[j];

        sort(p, p+l1);
        
        rep(j,0,l1){
            if(p[j]!=j+1){
                f2 = 0;
            }
        }

        if(l1 == l2){
            cout<<res<<"\n";
            rep(i,0,res)
                cout<<ans[i].first<<" "<<ans[i].second<<"\n";
            continue;
        }

        if(f1 && f2){
            res++;
            ans.pb(mk(l2, l1));
        }

        cout<<res<<"\n";
        rep(i,0,res){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }  
    }
    return 0;
}