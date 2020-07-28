#include <bits/stdc++.h>

using namespace std;

void func(vector<char> list, int i, int n) {
    int j, temp;
    if(i==n) { 
        for(j=0; j<=n; j++)
            cout<<list[j];
        cout<<" ";
    }
    else
        for(j=i; j<=n; j++) {
            swap(list[i], list[j]);    
            func(list, i+1, n);
            swap(list[i], list[j]);
        }
}

int main()
{   
    func({'a', 'b', 'c'}, 0, 2);
}