#include<bits/stdc++.h>
#include<chrono>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define pb push_back
#define mk make_pair

char INPUT_FILE[] = "ip.txt";
char OUTPUT_FILE[] = "op.txt";

int main(){
    auto begin = chrono::high_resolution_clock::now();
    // freopen(INPUT_FILE, "r", stdin);
    // freopen(OUTPUT_FILE, "w", stdout);

    int T;
    cin>>T;
    
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int n = 7;
        string combinations[7] = {"a", "b", "c", "ab", "ac", "bc", "abc"};
        int mx = 1<<n, maxCount = -1;
        for(int mask = 0; mask < mx; mask++){
            int arr[n] = {a,b,c}, count = 0, flag = true;
            // cout<<mask<<" ";
            for(int i = 0; i < n; i++){
                if(mask & (1<<i)){
                    // cout<<i<<" ";
                    for(char ch: combinations[i]){
                        if(!arr[ch - 'a']){
                            flag = false;
                            break;
                        }
                        else
                            arr[ch - 'a']--;
                    }
                    count++;
                }
            }
            // cout<<endl;
            if(flag){
                // cout<<count<<endl;
                maxCount = max(maxCount, count);
            }
            
        }
        cout<<maxCount<<endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::milliseconds>(end - begin);
    // cout<<dur.count()<<endl;
}