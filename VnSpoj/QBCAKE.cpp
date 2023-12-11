#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

int s(point a, point b, point c){
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

const int N = 3005;
point pt[N]; int a[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    cout.precision(1); fixed(cout);
    int n, res = 0; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> pt[i].x >> pt[i].y; pt[i + n] = pt[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 2, k = i + 1; j < i + n - 1; j++){
            a[i][j % n] = s(pt[i], pt[j], pt[k]);
            while (k + 1 < j && a[i][j % n] < s(pt[i], pt[j], pt[k + 1]))
                a[i][j % n] = s(pt[i], pt[j], pt[++k]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res = max(res, a[i][j] + a[j][i]);
    cout << 1.0 * res / 2.0 << '\n';
}