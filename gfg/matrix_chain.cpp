#include<bits/stdc++.h>
using namespace std;

class MatrixMul{
    int *p;
    int n;
    int **split;

    public:
        MatrixMul(int p[],int n){
            this->p = p;
            this->n = n-1;
            split = new int*[this->n];
            for(int i=0;i<this->n;i++){
                split[i] = new int[this->n];

                memset(split[i],0,sizeof(int)*this->n);
            }
            // for(int i=0;i<n-1;i++){
            //     for(int j=0;j<n-1;j++)
            //         cout<<split[i][j]<<" ";
            //     cout<<endl;
            // }
        }
        int MinimumCost();
        void printBrackets(int,int,char&);

};

int MatrixMul::MinimumCost(){
    int dp[n][n];
    memset(dp,0,sizeof(dp));

    for(int gap=1;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            dp[i][j] = INT_MAX;
            int cost;
            for(int k=i;k<j;k++){
                cost = dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1];
                if(cost<dp[i][j]){
                    dp[i][j] = cost;
                    split[i][j]=k;
                }
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<split[i][j]<<" ";
    //     cout<<endl;
    // }
    return dp[0][n-1];
}

void MatrixMul::printBrackets(int i,int j, char &name){
    if(i==j) {
        cout<<name++;
        return;
    }

    cout<<"(";
    printBrackets(i,split[i][j],name);
    printBrackets(split[i][j]+1,j,name);
    cout<<")";

}


int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int p[n];
        for(int i=0;i<n;i++) cin>>p[i];

        MatrixMul m(p,n);
        cout<<m.MinimumCost()<<endl;
        char name='A';
        m.printBrackets(0,n-2,name);
        cout<<endl;


    }
}