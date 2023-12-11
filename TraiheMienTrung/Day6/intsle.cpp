#include <bits/stdc++.h>
using namespace std;
int ax, bx, cx, ay, by, cy;

bool check(int a, int b, int c) {
    if (a == 0 && b == 0) {
        if (c == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if (c % __gcd(a,b) == 0) {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("intsle.inp", "r", stdin);
    freopen("intsle.out", "w", stdout);
    int test; cin >> test;

    while (test--) {
        cin >> ax >> bx >> cx >> ay >> by >> cy;
        int d = ax * by - ay * bx;
        int dx = cx * by - cy * bx;
        int dy = ax * cy - ay * cx;

        if (d == 0) {
            if (dx != 0 || dy != 0) {
                cout << "NO SOLUTION" << '\n';
            }
            else {
                if (check(ax, bx, cx) && check(ay, by, cy)) {
                    cout << "INFINITE" << '\n';
                }
                else {
                    cout << "NO SOLUTION" << '\n';
                }
            }
        }
        else {
            int x = dx / d;
            int y = dy / d;

            if (dx % d == 0 && dy % d == 0) {
                cout << x << " " << y << '\n';
            }
            else {
                cout << "NO SOLUTION" << '\n';
            }
        }
    }
}
