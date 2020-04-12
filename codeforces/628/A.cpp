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
        ll x;
        cin>>x;
        bool flag = false;
        if(x==2){
            cout<<"1 1"<<endl;
            continue;
        }
        if(x%2)
            x--;
        else{
            x -= 2;
            x /= 2;
            flag = true;
        }
            
        int a = 1;
        while(x && x%2==0){
            a*=2;
            x/=2;
        }

        if(flag){
            a = a<<1;
            x = x<<1;
        }
            
        cout<<a<<" "<<x<<endl;
        

    }
    return 0;
}