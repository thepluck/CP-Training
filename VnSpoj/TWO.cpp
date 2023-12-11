#include <bits/stdc++.h>
using namespace std;

struct machine{
    int x, y, id;
};

const int N = 1e4 + 5;
machine hh[N]; int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> hh[i].x;
    for (int i = 1; i <= n; i++){
        cin >> hh[i].y; hh[i].id = i;
    }
    sort(hh + 1, hh + n + 1, 
    [](const machine &a, const machine &b){
        if (a.x <= a.y && b.x <= b.y)
            return a.x < b.x;
        if (a.x > a.y && b.x > b.y)
            return a.y > b.y;
        if (a.x <= a.y) return true;
        return false;
    });
    int ta = hh[1].x, tb = hh[1].x + hh[1].y;
    for (int i = 2; i <= n; i++){
        ta += hh[i].x;
        if (ta >= tb) tb = ta + hh[i].y;
        else tb += hh[i].y;
    }
    cout << tb << '\n';
    for (int i = 1; i <= n; i++)
        cout << hh[i].id << ' ';
}