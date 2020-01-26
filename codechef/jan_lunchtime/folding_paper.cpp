// Solved in Practice after contest.

#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        ld w,h;
        cin>>n>>m>>w>>h;

        vector<pair<ld,ld>> points(m);
        int i,j;
        string moves;

        cin>>moves;
        rep(i,0,m){
            pair<ld,ld> point;
            cin>>point.first>>point.second;
            points[i] = point;
        }
        // cout<<endl<<"Points: ";
        // for(auto point: points)
        //     cout<<point.first<<" "<<point.second<<endl;
        // cout<<"done\n";

        ld x1,y1,x2,y2,dist,minDist = 1e11;

        // Calculating initial minDist from original points without reflection
        rep(i,0,m-1){
            rep(j,i+1,m){
                x1 = points[i].first; y1 = points[i].second;
                x2 = points[j].first; y2 = points[j].second; 
                // cout<<x1<<" "<<y1<<"  "<<x2<<" "<<y2<<endl;
                dist = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
                // cout<<(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)<<" ";
                minDist = min(minDist, dist);
            }
        }
        // cout<<endl<<minDist<<endl<<endl;

        // L R U D
        ld boundaries[4] = {0,w,h,0};
        bool found[4];
        memset(found,false,sizeof(found));
        bool done = false;
        for(char ch: moves){
            if(ch=='L') 
                (found[0] == true)?found[1]=true:found[0]=true;
            else if(ch == 'R') 
                (found[1] == true)?found[0]=true:found[1]=true;
            else if(ch == 'U') 
                (found[2] == true)?found[3]=true:found[2]=true;
            else if(ch == 'D') 
                (found[3] == true)?found[2]=true:found[3]=true;
        
            rep(i,0,4)
                done &= found[i];
            if(done)
                break;
        }

        // Checking if minDist is between reflection of any point during unfolding
        rep(i,0,2){
            if(found[i])
                for(auto point: points)
                    minDist = min(minDist, 2*abs(point.first - boundaries[i]));
        }
        rep(i,2,4){
            if(found[i])
                for(auto point: points)
                    minDist = min(minDist, 2*abs(point.second - boundaries[i]));
        }
        // cout <<fixed<<setprecision(11);
        cout<<minDist<<endl;
    }
    return 0;

}