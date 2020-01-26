#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        float n,k,l;
        int m;
        cin>>m>>n>>k>>l;

        float interval = k+l;
        int num_intervals = n/interval;

        float talks = num_intervals*k;
        int work = n - talks;

        cout<<min(m,work)<<endl;
    }
}