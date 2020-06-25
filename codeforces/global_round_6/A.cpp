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
        int i, j, n;
        string s;
        cin>>s;
        bool by2 = false, by3 = false;
        int zeroes = 0;
        int sum = 0;
        for(char c: s){
            int d = c - '0';
            sum += d;
            if(d%2==0 && d) by2 = true;
            if(d==0) zeroes++;   
        }
        if(sum%3==0) by3 = true;

        if(by3 && (zeroes>1 || zeroes==1 && by2)){
            cout<<"red\n";
        }
        else{
            cout<<"cyan\n";
        }
    }
   
    return 0;
}