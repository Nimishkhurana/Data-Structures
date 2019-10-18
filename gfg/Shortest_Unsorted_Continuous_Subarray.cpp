#include<bits/stdc++.h>
using namespace std;

// O(nlogn) sorting approach
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(),sorted_nums.end());
        
        int i;
        for(i=0;i<n;i++){
            if(nums[i] != sorted_nums[i])
                break;
        }
        if(i==n) return 0;
        int j;
        for(j=n-1;i>=0;j--){
            if(nums[j] != sorted_nums[j])
                break;
        }
        
        return j-i+1;
        
    }
};

// O(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return 0;
        int l,r;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                l=i;
                break;
            }
                
        }
        if(l==n-1) return 0;
        for(int j=n-1;j>0;j--){
            if(nums[j]<nums[j-1]){
                r = j;
                break;
            }      
        }
        
        int minn = INT_MAX,maxx = INT_MIN;
        
        for(int i=l;i<=r;i++){
            maxx = max(maxx,nums[i]);
            minn = min(minn,nums[i]);
        }
        cout<<minn<<" "<<maxx<<endl;
        cout<<l<<" "<<r<<endl;
        while(l>=0 && nums[l]>minn) l--;
        while(r<n && nums[r]<maxx) r++;
        cout<<l<<" "<<r<<endl;
 
        return r-l-1;
    }
};