#include<iostream>
using namespace std;

int MooreVotingCandidate(int arr[], int n){
    int maj_ind = 0;
    int maj_element = arr[maj_ind];
    int count = 1;

    for(int i=1;i<n;i++){
        if(arr[i]==maj_element){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            maj_ind = i;
            maj_element = arr[maj_ind];
            count=1;
        }
    }

    return maj_element;
}

bool MooreVotingConfirm(int arr[], int n, int maj_element){
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==maj_element){
            count++;

            if(count>n/2)
                return true;
        }
    }
    return false;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        int maj_candidate = MooreVotingCandidate(arr,n);
        if(MooreVotingConfirm(arr,n,maj_candidate))
            cout<<maj_candidate;
        else
            cout<<-1;
        cout<<endl;
    }
}