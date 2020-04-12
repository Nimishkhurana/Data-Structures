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
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}


int main(){
    // fast 
    int T;
    cin>>T;
    while(T--){
        int i, j, n, k;
        cin>>n>>k;
        int a[n];
        rep(i, 0, n) cin>>a[i];
        sort(a, a + n, greater<int>());
        i = 0, j = n-1;
        int sum = 0, c= 0, ans = 0;
        while(i < j){
            if(a[i] < k) {
                i++;
                continue;
            }
            sum = a[i];
            c = 1;
            while(i < j){
                sum += a[j];
                c++;
                if(sum < c*k)
                    break;
                j--;
            }
            if(i==j) ans++;
            cout<<i<<" "<<c-1<<"\n";
            ans += (c - 1);
            i++;
        }

        cout<<ans<<"\n";
    }
    return 0;
}