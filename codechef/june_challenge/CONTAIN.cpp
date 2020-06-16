//Author: nimishkhurana
//Sources: https://stackoverflow.com/questions/217578/how-can-i-determine-whether-a-2d-point-is-within-a-polygon
//https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html
// https://cp-algorithms.com/geometry/point-in-convex-polygon.html
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umapi unordered_map<ll,ll>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define vi vector<ll> 
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define mk make_pair
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INF 10000000000

#define NO 0
#define YES 1
#define COLLINEAR 2

// template <typename T>
// ostream& operator << (ostream& stream, const pair<T,T> &p) {
//     return stream<<"("<<p.first<<","<<p.second<<") ";
// }

const ll mxn = 5000, mxq = 2000;
ll n, q;

struct pt{
    ll x, y;
    pt(){}
    pt(long long _x, long long _y):x(_x), y(_y){}
    bool operator < (const pt &p) const { return mk(x,y) < mk(p.x, p.y);}
    bool operator == (const pt &p) const { return mk(x,y) == mk(p.x, p.y);}
    pt operator+(const pt & p) const { return pt(x + p.x, y + p.y); }
    pt operator-(const pt & p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt & p) const { return x * p.y - y * p.x; }
    long long dot(const pt & p) const { return x * p.x + y * p.y; }
    long long cross(const pt & a, const pt & b) const { return (a - *this).cross(b - *this); }
    long long dot(const pt & a, const pt & b) const { return (a - *this).dot(b - *this); }
    long long sqrLen() const { return this->dot(*this); }
};

ostream& operator<<(ostream& os, const pt& p){
    return os << "("<<p.x << " " << p.y << ") ";
}

set<pt> pts;
vector<vector<pt>> polygons;

// bool isBetween(pt a, pt b, pt p){
//     ll crossproduct = (p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y);

//     if(crossproduct != 0)
//         return false;

//     if(p.x >= min(a.x,b.x) && p.x <= max(a.x, b.x) && p.y >= min(a.y,b.y) && p.y <= max(a.y,b.y))
//         return true;

//     return true;
// }

bool isBetween(pt a, pt b, pt pt_to_check){
    ll crossproduct = (pt_to_check.y - a.y) * (b.x - a.x) - (pt_to_check.x - a.x) * (b.y - a.y);

    if(abs(crossproduct) != 0)
        return false;

    ll dotproduct = (pt_to_check.x - a.x) * (b.x - a.x) + (pt_to_check.y - a.y)*(b.y - a.y);
    if(dotproduct < 0)
        return false;

    ll squaredlengthba = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
    if(dotproduct > squaredlengthba)
        return false;

    return true;
}


// ##############################################################################################################################
// ##
// ##   Convex Hull Graham Scan Algo
// ##
// ###############################################################################################################################

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

bool isPointOnPolygon(pt pt_to_check, vector<pt> &polygon){
    ll sz = polygon.size();
    for(ll i = 0; i < sz; i++){
        pt a = polygon[i], b = polygon[(i+1)%sz];
        if(pt_to_check==a || pt_to_check==b || isBetween(a, b, pt_to_check)){
            return true;
        }
    }
    return false;
}

void remove_on_polygon_boundary_pts(vector<pt> polygon){
    vector<pt> pts_to_erase;
    for(auto pt_to_check: pts){
        if(isPointOnPolygon(pt_to_check, polygon)){
            pts_to_erase.emplace_back(pt_to_check);
        }
    }
    //cerr<<"Erase: ";
    for(pt to_erase: pts_to_erase){
        //cerr<<to_erase;
        pts.erase(to_erase);
    }
    //cerr<<'\n';
}

void convex_hull() {
    if(pts.size() < 3) return;

    vector<pt> a(pts.begin(), pts.end());

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (ll i = 1; i < (ll)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]), pts.erase(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]), pts.erase(down[i]);

    polygons.emplace_back(a);
    remove_on_polygon_boundary_pts(a);
    convex_hull();
}


int pnpoly(int nvert, vector<pt> & points, pt to_check){
  int i, j, c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ((points[i].y>to_check.y) != (points[j].y>to_check.y) && (points[i].y - points[j].y)){
        ld lhs = (ld)to_check.x/(ld)(1.0);
        ld rhs = (ld)(points[j].x-points[i].x)*(to_check.y-points[i].y)/(ld)(points[j].y-points[i].y) + points[i].x;
        if(lhs < rhs)
             c = !c;
    }
  }
  return c;
}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    ll T;
    cin>>T;
    while(T--){
        ll i, j;
        cin>>n>>q;
        vector<pt> points(n);
        pts.clear();
        polygons.clear();
        rep(i, 0, n){
            cin>>points[i].x>>points[i].y;
            pts.insert(points[i]);
        }

        convex_hull();
        ll polygons_count = polygons.size();

      
        //cerr<<polygons_count<<"\n";
        pt candle;
        while(q--){
            ll x, y;
            cin>>x>>y;
            candle = pt({x,y});
            ll ans = polygons_count;
            ll ans2 = 0;
            rrep(i, polygons_count-1, 0){
                
                auto &polygon = polygons[i];
                if(isPointOnPolygon(candle, polygon)){
                    //cerr<<"ON\n";
                    ans--;
                    // break;
                }
                else if(pnpoly((int)polygon.size(), polygon, candle)){
                    //cerr<<"INSIDE\n";
                    // ans2++;
                    break;
                }
                else {
                    ans--;
                   // cerr<<"OUTSIDE\n";
                }
            }
            cout<<ans<<"\n";
        }
    }
   
    return 0;
}