#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

// -1 for invalid move
// 0 for valid move
// 1 for valid move that ends the game
int make_a_move(vector<int>& a, int x, int y) {
    if (y < 0 || x <= y) {
        return -1;
    }
    if (find(a.begin(), a.end(), y) != a.end()) {
        return -1;
    }
    if (auto it = find(a.begin(), a.end(), x); it == a.end()) {
        return -1;
    } else {
        *it = y;
        if (*max_element(a.begin(), a.end()) == a.size() - 1) {
            return 1;
        } else {
            return 0;
        }
    }
}

// find a next valid move that forces grundy to be 0
pair<int, int> inverse_welter(vector<int>& a) {
    int k = a.size();
    vector w(k + 1, vector<int>(2 * k + 1));
    for (int i = 0; i < k; i++) {
        w[1][i] = a[i];
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < k + 1 - i; j++) {
            w[i][j] = ((w[i - 1][j] ^ w[i - 1][j + 1]) - 1) ^ w[i - 2][j + 1];
        }
    }
    if (w[k][0] == 0) {
        sort(a.begin(), a.end());
        int tot = 0;
        for (int i = 0; i < k; i++) {
            tot += a[i] - i;
        }
        int nxt = rnd.next(tot);
        for (int i = 0; i < k; i++) {
            if (nxt < a[i] - i) {
                for (int j = 0; j <= i; j++) {
                    int l = (j == 0 ? 0 : a[j - 1] + 1), r = a[j];
                    if (nxt < r - l) {
                        return {a[i], l + nxt};
                    } else {
                        nxt -= r - l;
                    }
                }
            } else {
                nxt -= a[i] - i;
            }
        }
        quitf(_fail, "judge cannot find a valid move");
    } else {
        for (int i = 1; i <= k; i++) {
            w[k][i] = (i % 2 == 1 ? 0 : w[k][0]);
        }
        for (int j = 0; j < k; j++) {
            for (int i = k - 1; i >= 1; i--) {
                int p = j + (k + 1 - i);
                w[i][p] = ((w[i - 1][p] ^ w[i + 1][p - 1]) + 1) ^ (w[i][p - 1]);
            }
        }
        vector<pair<int, int>> nxt;
        for (int i = 0; i < k; i++) {
            if (w[1][i] > w[1][i + k]) {
                nxt.push_back({w[1][i], w[1][i + k]});
            }
        }
        quitif(nxt.empty(), _fail, "judge cannot find a valid move");
        // return any in nxt
        return rnd.any(nxt);
    }
}

int main(int argc, char **argv) {
    registerInteraction(argc, argv);
    int t = inf.readInt();
    cout << t << endl;
    for (int tc = 1; tc <= t; tc++) {
        setTestCase(tc);
        int n = inf.readInt(), k = inf.readInt();
        cout << n << " " << k << endl;
        vector<int> a(k);
        iota(a.begin(), a.end(), n - k);
        string player = ouf.readToken("Alice|Bob");
        for (int turn = (player == "Alice");; turn ^= 1) {
            if (turn) {
                string cmd = ouf.readToken("move");
                int x = ouf.readInt(), y = ouf.readInt();
                int verdict = make_a_move(a, x, y);
                if (verdict < 0) {
                    cout << "invalid -1 -1" << endl;
                    quitf(_wa, "player made an invalid move: %d -> %d", x, y);
                }
                if (verdict == 1) {
                    cout << "end -1 -1" << endl;
                    break;
                }
            } else {
                auto [x, y] = inverse_welter(a);
                int verdict = make_a_move(a, x, y);
                quitif(verdict == -1, _fail, "judge made an invalid move: %d -> %d", x, y);
                if (verdict == 1) {
                    cout << "end " << x << ' ' << y << endl;
                    quitf(_wa, "judge won");
                }
                cout << "move " << x << ' ' << y << endl;
            }
        }
    }
    quitf(_ok, "player got hands");
}
