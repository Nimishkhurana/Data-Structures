#include<bits/stdc++.h>
using namespace std;

template< typename T>
vector<int> prefix_function(T const &p){
    int m = p.size();
    
    vector<int> lps(m+1, 0);
    int i = 0, j = lps[0] = -1;
    
    while(i < m){
        while(~j && p[i] != p[j]) j = lps[j];
        lps[++i] = ++j;
    }

    return lps;
}

template< typename T>
vector<int> kmp(T const &s, T const &p, bool overlapping = true){
    vector<int> lps = prefix_function(p);

    int n = s.size(), m = p.size();
    int i = 0, j = 0;

    vector<int> occurrences;
    while(i < n){
        while(~j && s[i] != p[j]) j = lps[j];
        i++, j++;
        if(j == m) {
            occurrences.push_back(i - m);
            if(overlapping)
                j = lps[j]; //overlapping allowed
            else 
                j = 0 // for disjoint occurrences
        }
    }
    return occurrences;
}

int main(){
    //Test
    string s, p;
    cin>>s>>p;
    // vector<int> s = {1, 2, 3, 3, 0, 4}, p = {};
    auto occurences = kmp(s, p);
    for(int ind: occurences){
        cerr<<ind<<" ";
    }
}