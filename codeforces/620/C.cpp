#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define pb push_back

struct Cust{
    int t,l,h;
    Cust(int t, int l, int h): t(t), l(l), h(h){}
    Cust(){}
}c[101];

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int i;
        int minn = m, maxx =m;
        int t,l,h;
        rep(i,0,n){
            cin>>t>>l>>h;
            Cust customer(t,l,h);
            c[i] = customer;
        }

        // cout<<"h";
        int prev_t = 0;
        rep(i,0,n){
            int t = c[i].t, l = c[i].l, h = c[i].h;
            maxx += (t - prev_t);
            maxx = min(maxx, h);
            minn -= (t - prev_t);
            minn = max(minn, l);
            // cout<<maxx<<" "<<minn<<endl;
            if(maxx < l || minn > h){
                cout<<"NO\n";
                break;
            }
            prev_t = t;
        }
        if(i == n)
            cout<<"YES\n";
    }
    return 0;
}