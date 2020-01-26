#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int temp = n;
        int len=0;
        while(temp){
            len++;
            temp/=10;
        }
        // cout<<"len="<<len<<endl;
        temp=n;
        int req_scale=-1;
        for(int i=len-1;i>0;i--){
            int scale = (int)(pow(10,i)+0.5);
            int next_sc = (int)(pow(10,i-1)+0.5);
            // cout<<scale<<" "<<next_sc<<"  ";
            int digit = temp/scale %10;
            int next = temp/next_sc %10;

            if(digit>next){
                req_scale = scale;
                break;
            }
        }
        temp = n;
        int lsb = temp%req_scale;
        int msb = temp/(req_scale*10);
        // cout<<req_scale<<endl;
        // cout<<msb<<" "<<lsb<<endl;

        int num = msb*req_scale + lsb;
        cout<<num<<endl;
    }
}