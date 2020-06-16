//Author: nimishkhurana
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umapi unordered_map<ll,ll>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define vi vector<ll> 
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


const ll n = 3;
ll a[n], b[n], d[n];

// roots of eqtns a1x + y = b1 and a2x + y = b2.
pair<bool, pii> roots1(ll a1, ll b1, ll a2, ll b2){
    pair<bool, pii> res;
    if(!(b2-b1) && !(a2-a1)) res = {true, {1, b1-a1}};
    else if(!(a2 - a1) || (b2 - b1)%(a2 - a1)) res = {false, {0,0}};
    else{
        ll x = (b1-b2)/(a1-a2);
        if((a1*b2 - a2*b1)%(a1-a2)) res = {false, {0,0}};
        else{
            ll y = (a1*b2 - a2*b1)/(a1-a2);
            res = {true, {x, y}};
        }
        
    }
    return res;
}

// roots of eqtns (a1+y)x = b1 and (a2+y)x = b2.
pair<bool, pii> roots2(ll a1, ll b1, ll a2, ll b2){

    pair<bool, pii> res;
    if(!(b2-b1) && !(a2-a1)) res = {true, {1, b1-a1}};
    else if(!(a2 - a1) || !(b2-b1) || (b2 - b1)%(a2 - a1)) res = {false, {0,0}};
    else{
        ll x = (b2-b1)/(a2-a1);
        if(!x || b1%x) res = {false, {0,0}};
        else{
            ll y = b1 / x - a1;
            res = {true, {x, y}};
        }
    }
    return res;
}

bool isRoot(ll k, ll x, ll y){
    if(a[k]*x + y == b[k] || a[k]*x == b[k] || a[k] + y == b[k])
        return true;
    else return false;
}

bool isRoot2(ll k, ll x, ll y){
    if((a[k] + y)*x == b[k] || a[k]*x == b[k] || a[k] + y == b[k])
        return true;
    else return false;
}

bool isFactor(ll x, ll y){
    if(x && y%x==0) return true;
    return false;
}

ll cost(ll i, ll j, ll k){
    ll cost = 3;
    auto roots = roots1(a[i], b[i], a[j], b[j]);  
    if(roots.first){
        ll x = roots.second.first, y = roots.second.second, cur = 3;
        if(isRoot(k, x, y)) cur--;
        else if(a[k]==b[k]) cur--;
        if(x==1) cur--;
        if(y==0) cur--;
        // cerr<<"1  "<<i<<" "<<j<<"  "<<x<<" "<<y<<"  "<<cur<<"\n";
        cost = min(cur, cost);
    }
    else{
        if(isFactor(a[j], b[j]) && isRoot(i, b[j]/a[j], b[k]-a[k])){
            cost = 2;
            if(b[j]/a[j]==1LL) cost--;
            if(b[k]-a[k]==0) cost--;
        }
            
        if(isFactor(a[k], b[k]) && isRoot(i, b[k]/a[k], b[j]-a[j])){
            cost = 2;     
            if(b[k]/a[k]==1LL) cost--;
            if(b[j]-a[j]==0) cost--;
        }       
    }

    if(isFactor(a[i], b[i]) && isFactor(a[j], b[j]) && isFactor(a[k], b[k])){
        ll q1 = b[i]/a[i], q2 = b[j]/a[j], q3 = b[k]/a[k];
        if(q1*q2 == q3) cost = 2; 
    }

    if(d[i] + d[j] == d[k]) cost = 2;

    roots = roots2(a[i], b[i], a[j], b[j]);  
    if(roots.first){
        ll x = roots.second.first, y = roots.second.second, cur = 3;
        if(isRoot2(k, x, y)) cur--;
        else if(a[k]==b[k]) cur--;
        if(x==1LL) cur--;
        if(y==0) cur--;
        // cerr<<"2  "<<i<<" "<<j<<"  "<<y<<" "<<x<<"  "<<cur<<"\n";
        cost = min(cur, cost);
    }
    else{
        if(isFactor(a[j], b[j]) && isRoot2(i, b[j]/a[j], b[k]-a[k])){
            cost = 2;
            if(b[j]/a[j]==1LL) cost--;
            if(b[k]-a[k]==0) cost--;
        }
            
        if(isFactor(a[k], b[k]) && isRoot2(i, b[k]/a[k], b[j]-a[j])){
            cost = 2;     
            if(b[k]/a[k]==1LL) cost--;
            if(b[j]-a[j]==0) cost--;
        }       
    }
    if(isFactor(a[i], b[i])){
        ll x = b[i]/a[i];
        ll y = b[j] - a[j];
        if(isRoot(k, x, y) || isRoot2(k, x, y)){
            cost = min(cost, 2LL);
        }
    }
    return cost;
}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    ll T;
    cin>>T;
    while(T--){
        ll i, j;
        
        rep(i, 0, n) cin>>a[i];
        rep(i, 0, n) cin>>b[i];

        ll ans = 3;
        rep(i, 0, n){
            d[i] = b[i] - a[i];
            if(d[i]==0) ans--;
        }

        if(b[0]==b[1] && b[1]==b[2]){
            if(b[0]==0)
                ans = min(ans, 1LL);
            else 
                ans = min(ans, 2LL);
        }

        rep(i, 0, n){
            rep(j, 0, n){
                if(i != j)
                    ans = min({ans, cost(i, j, n-(i+j)), cost(j, i, n-(i+j)) });
            }
        }

        cout<<ans<<"\n";  
    }
   
    return 0;
}