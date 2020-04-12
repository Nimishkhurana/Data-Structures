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

int chartoint(char c){
    return c - '0';
}

char inttochar(int n){
    return n + '0';
}

int main(){
    fast 
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string x, a, b;
        cin>>x;
        int i, t;
        rep(i,0,n){
            if(x[i]=='2'){
                a.pb('1'), b.pb('1');
            }
            else if(x[i]=='0')
                a.pb('0'), b.pb('0');
            else {
                a.pb('1'), b.pb('0');
                break;
            }
        }

        int j;
        rep(j, i+1, n){
            a += '0';
            b += x[j];
        }

        cout<<a<<"\n"<<b<<"\n";

    }
    return 0;
}