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
        ll n;
        cin>>n;
        if(n==1){
            cout<<"FastestFinger\n";
            continue;
        }
        int odds = 0, evens = 0;
        while(!(n&1)){
            evens++;
            n>>=1;
        }

        for(int i = 3; i*i <= n; i+=2){
            while(n%i==0){
                odds++;
                n /= i;
            }
        }
        if(n > 2) odds++;

        // cerr<<evens<<" "<<odds<<"\n";
        if(!evens){
            cout<<"Ashishgup\n";
            continue;
        }

        if(evens==1){
            if(odds > 1 || odds == 0){
                cout<<"Ashishgup\n";
            }
            else if(odds==1){
                cout<<"FastestFinger\n";
            }
        }
        else{
            if(odds > 0){
                cout<<"Ashishgup\n";
            }
            else{
                cout<<"FastestFinger\n";
            }
        }
    }
   
    return 0;
}