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

int n, k;
const int mxn = 2e5+1;
ll a[mxn], b[mxn];

bool ok(int x){
    int i;
    // cerr<<"\n";
    bool turn;
    for(int j = 0; j < 2; j++){
        turn = !(j && (a[0] <= x));
        int count = 1;
        rep(i, 1, n){
            if(turn && a[i] <= x){
                count++;
                turn = 0;
            }
            else if(!turn){
                count++;
                turn = 1;
            }
        }
        // cerr<<turn<<" "<<count<<"\n";
        if(count >= k) return true;
    }
    
    return false;
}

int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin>>n>>k;
    int i, j;

    rep(i, 0, n){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b, b+n);
    int l = 0, r = n;
    int mid;
    while(l < r){
        mid = (l+r)/2;
        // cerr<<l<<" "<<mid<<" "<<r<<"   ";
        if(ok(b[mid])){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    // cerr<<l<<"\n";
    cout<<b[l]<<"\n";
   
    return 0;
}