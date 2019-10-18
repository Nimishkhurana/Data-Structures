#include<iostream>
using namespace std;

long long ioffset[] = {0,-1,0,0,1};
long long joffset[] = {0,0,-1,1,0};

bool isSafe(long long i, long long j){
    if((i>=0 && i<3 && j>=0 && j<3) || (i==3 && j==1))
        return true;
    return false;
}

long long maxNumbers(long long N){

    char keypad[][3] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'}};
    long long dp[10][N+1];

    if(N==1)
        return 10;

    for(long long i=0;i<10;i++){
        dp[i][0]=0;
        dp[i][1]=1;
    }


    for(long long n=2;n<=N;n++){
        for(long long i=0;i<4;i++){
            for(long long j=0;j<3;j++){
                if (isSafe(i,j)){
                    long long digit = keypad[i][j] - '0';
                    long long nextDigit;
                    dp[digit][n]=0;
                    
                    for(long long move=0;move<5;move++){
                        long long r = i+ioffset[move];
                        long long c = j+joffset[move];

                        if(isSafe(r,c)){
                            nextDigit = keypad[r][c] - '0';
                            dp[digit][n] += dp[nextDigit][n-1];
                        }
                    }
                }           
            }
        }
    }
    long long ans=0;
    for(long long num=0;num<10;num++){
        ans+=dp[num][N];
    }
    return ans;
}

int main(){
    long long t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<maxNumbers(n)<<endl;
    }
}