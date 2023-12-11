#include    <bits/stdc++.h>
using   namespace   std;

char s[5][5];

int main() {
    freopen("caro.inp", "r", stdin);
    freopen("caro.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    for (int i = 1; i <= 3; i++)
        scanf("%s", s[i] + 1);
    int dx, dy; dx = dy = 0;
    for (int i = 1; i <= 3 ; i++)
        for (int j = 1; j <= 3; j++) {
            dx += (s[i][j] == 'X');
            dy += (s[i][j] == '0');
        }
    if (dy > dx || dx > dy + 1) {
        cout << "invalid"; return 0;
    }
    int okx, oky; okx = oky = 0;
    for (int i = 1; i <= 3; i++) {
        int x, y; x = y = 0;
        for (int j = 1; j <= 3; j++) {
            x += (s[i][j] == 'X');
            y += (s[i][j] == '0');
        }
        okx += (x == 3);
        oky += (y == 3);
    }
    for (int j = 1; j <= 3; j++) {
        int x, y; x = y = 0;
        for (int i = 1; i <= 3; i++) {
            x += (s[i][j] == 'X');
            y += (s[i][j] == '0');
        }
        okx += (x == 3);
        oky += (y == 3);
    }
    int i = 1, j = 1, x, y; x = y = 0;
    while (i <= 3) {
        x += (s[i][j] == 'X');
        y += (s[i][j] == '0');
        i++; j++;
    }
    okx += (x == 3); oky += (y == 3);
    x = y = 0; i = 1; j = 3;
    while (i <= 3) {
        x += (s[i][j] == 'X');
        y += (s[i][j] == '0');
        i++; j--;
    }
    okx += (x == 3); oky += (y == 3);
    if (okx > 0 || oky > 0) {
        if (okx && oky ) cout << "invalid";
        else {
            if (okx > 2) cout << "invalid";
            else {
                if (okx) {
                    if (dx > dy) cout << "TL won";
                    else cout << "invalid";
                }
                else {
                    if (dx > dy) cout << "invalid";
                    else cout << "BD won";
                }
            }
        }
        return 0;
    }
    if (dx + dy == 9) {
        cout << "draw"; return 0;
    }
    if (dx > dy) cout << "BD was making a move";
    else cout << "TL was making a move";
}
