#include <bits/stdc++.h>
using namespace std;
using db=long double;
int n;
class point_t{
public:
    int x, y;
    point_t(){}
    point_t(int x, int y): x(x), y(y){}
};
point_t p[100000];
bool ccw(pair <int, db> O, pair <int, db> A, pair <int, db> B){
    A.first-=O.first;
    A.second-=O.second;
    B.first-=O.first;
    B.second-=O.second;
    return (A.second*B.first-B.second*A.first)<0;
}
bool cw(pair <int, db> O, pair <int, db> A, pair <int, db> B){
    A.first-=O.first;
    A.second-=O.second;
    B.first-=O.first;
    B.second-=O.second;
    return (A.second*B.first-B.second*A.first)>0;
}
bool check(db range){
    deque <pair <int, db>> hull;
    for(int i=0; i<n; i++){
        while((hull.size()>=2)&&(ccw(hull[hull.size()-2], hull[hull.size()-1], {p[i].x, -range+p[i].y}))) hull.pop_back();
        hull.push_back({p[i].x, -range+p[i].y});
    }
    hull.push_back(hull.back());
    for(int i=0; i<n; i++){
        while((hull.size()>2)&&(hull[1].first<p[i].x)) hull.pop_front();
        if(ccw(hull[0], {p[i].x, +range+p[i].y}, hull[1])) return 0;
    }
    hull.clear();
    for(int i=0; i<n; i++){
        while((hull.size()>=2)&&(cw(hull[hull.size()-2], hull[hull.size()-1], {p[i].x, +range+p[i].y}))) hull.pop_back();
        hull.push_back({p[i].x, +range+p[i].y});
    }
    hull.push_back(hull.back());
    for(int i=0; i<n; i++){
        while((hull.size()>2)&&(hull[1].first<p[i].x)) hull.pop_front();
        if(cw(hull[0], {p[i].x, -range+p[i].y}, hull[1])) return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>p[i].x>>p[i].y;
    sort(p, p+n, [](const point_t &a, const point_t &b){
        return a.x<b.x;
    });
    db low=0, high=2e6, mid;
    for(int i=0; i<100; i++){
        mid=(low+high)/2;
        if(check(mid)) high=mid;
        else low=mid;
    }
    cout<<setprecision(16)<<fixed<<(low+high)/2;
    // dbcheck((low+high)/2);
}