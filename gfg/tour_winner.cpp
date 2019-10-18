#include<bits/stdc++.h>
using namespace std;

int Tour_Winner(vector<vector<int>> strengths, int n){
    vector<int> winners;
    for(int i=0;i<n;i++)
        winners.push_back(i+1);
    
    
    

    for(int size=n;size>=1;size/=2){
        int counter=0;
        for(int i=0;i<size-1;i+=2){
        int first = i;
        int second = i+1;

        int count1=0,count2=0;
        for(int round=0;round<5;round++){
            if(strengths[first][round]>=strengths[second][round])
                count1++;
            else
                count2++;
        }
        if(count1 >= count2)
            winners[counter++] = first;
        else
            winners[counter++] = second;
    }

    }
    return winners[0];
    
}

int main(){
    int n;
    vector<vector<int>> strengths(n,vector<int>(5,0));
    

}