#include<bits/stdc++.h>
#include <iomanip>
#include<map>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>

int main(){
    int n,m,i,j;

    cin>>n;
    vector<int> boys(n);
    rep(i,0,n) cin>>boys[i];

    cin>>m;
    vector<int> girls(m);
    rep(i,0,m) cin>>girls[i];

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    i = n-1; j = m-1;
    int count = 0;
    while(i+1 && j+1){
        if(boys[i] == girls[j]){
            count++;
            i--;
            j--;
        }
        else if(boys[i]>girls[j]){
            if(boys[i] == girls[j]+1){
                count++;
                i--;
                j--;
            }
            else
                i--;
        }
        else{
            if(boys[i] == girls[j]-1){
                count++;
                i--;
                j--;
            }
            else
                j--;
        }
        // cout<<boys[i]<<" "<<girls[j]<<"  "<<count<<" ";
    }
    cout<<count<<endl;

}