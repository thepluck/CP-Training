#include <bits/stdc++.h>

using namespace std;

int division(int a, int b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int w, h, d;
    cin >> w >> h >> d;
    char s[2][2];
    s[0][0] = 'R'; s[0][1] = 'Y';
    s[1][0] = 'G'; s[1][1] = 'B';
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++)
            cout << s[division(i + j, d) & 1][division(i - j, d) & 1];
        cout << '\n';
    }
}