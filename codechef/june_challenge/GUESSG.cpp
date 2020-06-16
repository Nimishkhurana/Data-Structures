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

ll n;
void solve_linear(ll l, ll r, int &count, bool &found){
    char response;
    for(ll i = l; i <= r; i++){
        cout<<i<<"\n";
        cin>>response;
        if(response == 'E'){
            found = true;
            break;
        }
    }
}

bool makeLie(int &count, bool &found){
    int i;
    char response;
    rep(i, 0, 10){
        cout<<1<<"\n";
        cin>>response;
        if(response == 'E'){
            found = true;
            return true;
        }
        if(response == 'L') return true;
    }
    rep(i, 0, 0){
        cout<<n<<"\n";
        cin>>response;
        if(response == 'E'){
            found = true;
            return true;
        }
        if(response == 'G') return true;
    }
    return false;       
}

void solve(ll l, ll r, int &count, bool &found, bool lies){
    // cerr<<l<<" "<<r<<" "<<count<<'\n';
    if(found || r < l) return;

    if(r - l + 1 < 10){
        solve_linear(l, r, count, found);
        return;
    }
    char response;
   
    bool lied = false;

    if(lies){
        lied = makeLie(count, found);
        if(found) return;
    }
    
    ll q1, mid, q2;
    
    mid = l + (r-l)/2;
    cout<<mid<<"\n";
    cin>>response;

    if(lied){
        if(response == 'E'){
            found = true;
            return;
        }
        else if(response == 'G')
            solve(mid+1, r, count, found, lies);
        else 
            solve(l, mid-1, count, found, lies);
        return;
    }

    if(response == 'E'){
        found = true;
        return;
    }
    else if(response == 'G'){
        q1 = l + (r - l)/3;
       
        cout<<q1<<"\n";
        cin>>response;
        
        if(response == 'E') {
            found = true;
            return;
        }
            
        else if(response == 'G'){
            solve(q1+1, r, count, found, lies);
        }
        else if(response == 'L'){
            solve(mid+1, r, count, found, lies);
            solve(l, q1-1, count, found, lies);
        }
        else assert(false);
    }
    else if(response == 'L'){
        q2 = l + 2*(r - l)/3;

        cout<<q2<<"\n";
        cin>>response;

        if(response == 'E') {
            found = true;
            return;
        }
        else if(response == 'L'){
            solve(l, q2-1, count, found, lies);
        }
        else if(response == 'G'){
            solve(l, mid-1, count, found, lies);
            solve(q2+1, r, count, found, lies);
        }
        else assert(false);
    }   
    else assert(false);
}



int main(){
    
    cin>>n;
    int count = 0;
    bool found = false;
    bool lies = makeLie(count, found);
    
    solve(2, n, count, found, lies);

    cerr<<count<<"\n";
   
    return 0;
}