#include <bits/stdc++.h>
using namespace std;
 
struct pt{
    long long x, y;
};
 
bool cmp_y(const pt &a, const pt &b){
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}
 
bool ccw(const pt &a, const pt &b, const pt &c){
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
 
bool cw(const pt &a, const pt &b, const pt &c){
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
 
vector <pt> a, l, r;
int n, q;
 
void prepare(){
    int pos = 0;
    cin >> n; a.resize(n); 
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    for (int i = 1; i < n; i++)
        if (cmp_y(a[pos], a[i])) pos = i;
    rotate(a.begin(), a.begin() + pos, a.end());
    l.push_back(a[0]); 
    for (int i = 1; i < n; i++)
        if (a[i].y < a[i - 1].y) l.push_back(a[i]);
    for (int i = 0; i < n - 1; i++)
        if (a[i].y < a[i + 1].y) r.push_back(a[i]);
    r.push_back(a[n - 1]); r.push_back(a[0]);
}
 
bool ptinconvex(const pt &point){
    int lo = 0, hi = l.size() - 1, m, pos;
    bool cnd1, cnd2;
    if (point.y >= l[lo].y || point.y <= l[hi].y) 
        return false;
    while (lo <= hi){
        m = (lo + hi) / 2;
        if (l[m].y >= point.y){
            pos = m; lo = m + 1;
        }
        else hi = m - 1;
    }
    if (l[pos].y == point.y) cnd1 = point.x > l[pos].x;
    else cnd1 = cw(l[pos], point, l[pos + 1]);
    lo = 0; hi = r.size() - 1;
    while (lo <= hi){
        m = (lo + hi) / 2;
        if (r[m].y >= point.y){
            pos = m; hi = m - 1;
        }
        else lo = m + 1;
    }
    if (r[pos].y == point.y) cnd2 = point.x < r[pos].x;
    else cnd2 = ccw(r[pos], point, r[pos - 1]);
    return cnd1 && cnd2;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    prepare(); cin >> q; long long x, y;
    while (q--){
        cin >> x >> y;
        cout << (ptinconvex({x, y}) ? "YES\n" : "NO\n");
    }
} 