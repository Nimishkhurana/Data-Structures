// Solved in Practice after contest.

#include<bits/stdc++.h>
using namespace std;
#define for(i,a,b) for(i=a;i<b;i++)
#define ll long long int

const ll m = 2;
const ll n = 2;
#define MOD 1000000007

// Calculates a[][] = a[][]*b[][]
void matrix_mul(ll a[][n], ll b[][n]){
    ll c[m][n];
    memset(c,0,sizeof(c));
    ll i,j,k;

    for(i,0,m)
        for(j,0,n)
            for(k,0,n)
                c[i][k] = (c[i][k] + a[i][j]*b[j][k])%MOD;
    
    for(i,0,m)
        for(j,0,n)
            a[i][j] = c[i][j];
    
}
// Calculates res[][] = a[][]^e 
void pow(ll a[n][n], ll res[n][n], ll e){
    if(e<=0)
        return;

    if(e%2)
        matrix_mul(res,a);
    
    matrix_mul(a,a);  
    pow(a,res,e/2);   
}

int main(){
    ll t;
    cin>>t;
    
    while(t--){
        ll N,M;
        cin>>N>>M;
    
        if(!N || !M){
            cout<<0<<endl;
            continue;
        }

        ll a[n][n];
        a[0][0] = (M-1+MOD)%MOD;
        a[0][1] = (M-1+MOD)%MOD;
        a[1][0] = 1;
        a[1][1] = 0;
        ll res[n][n] = {{1,0},{0,1}};
        pow(a,res,N-1);

        ll F[2];
        F[0] = M%MOD;
        F[1] = 0;

        ll ans1 = ((res[0][0]*F[0]+MOD)%MOD+(res[0][1]*F[1]+MOD)%MOD+MOD)%MOD;
		ll ans2 = ((res[1][0]*F[0]+MOD)%MOD+(res[1][1]*F[1]+MOD)%MOD+MOD)%MOD;

		ll ans = (ans1+ans2+MOD)%MOD;
		cout<<ans<<endl;    
    }
}