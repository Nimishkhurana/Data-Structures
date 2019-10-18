#include<bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> s;

    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    
    int ans = 0;
    int curr;

    for(int i=0;i<n;i++){
        if(s.find(arr[i]-1)==s.end()){
            curr = 1;
            int t = arr[i];
            while(s.find(++t)!=s.end()){
                curr++;
            }
            ans = max(ans,curr);
        }
    }
  
  return ans;
}

// Driver program 
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    cout << "Length of the Longest contiguous subsequence is "
         << findLongestConseqSubseq(arr, n); 
    return 0; 
} 