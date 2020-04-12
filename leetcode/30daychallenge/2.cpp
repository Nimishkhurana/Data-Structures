#include<bits/stdc++.h>
using namespace std;

class Solution {
    int next(int n){
        // cout<<n<<" ";
        int res = 0;
        while(n){
            res += (n%10)*(n%10);
            n /= 10;
        }
        // cout<<res<<"\t";
        return res;
    }
   
public:
    bool isHappy(int n) {
        int slow = n, fast = next(n);
        if(slow==1 || fast==1)
            return true;
        while(slow!=fast){
            if(slow==1 || fast==1 || next(fast)==1 || next(slow)==1)
                return true;
            slow = next(slow);
            fast = next(next(fast));
        }
        return false;
    }
};

int main(){
    Solution S;
    int n;
    cin>>n;
    cout<<"\n";
    cout<<S.isHappy(n);
}