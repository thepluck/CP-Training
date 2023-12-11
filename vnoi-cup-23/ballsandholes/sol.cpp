#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << endl;
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n); fill(a.end() - k, a.end(), 1);
        int offset = 0;
        auto make_a_move = [&](int x, int y, bool print = true) {
            if (print) {
                cout << "move " << x << " " << y << endl;
            }
            a[x] ^= 1; a[y] ^= 1;
        };
        auto end_game = [&]() {
            return all_of(a.begin(), a.begin() + k, [](int x) { return x == 1; });
        };
        if (n % 2 == 1 && k % 2 == 1) {
            cout << "Alice" << endl;
            offset = 1;
            make_a_move(n - k, 0);
        } else if (n % 2 == 1 && k % 2 == 0) {
            cout << "Alice" << endl;
            make_a_move(n - 1, n - k - 1);
        } else if (n % 2 == 0 && k % 2 == 1) {
            cout << "Alice" << endl;
            offset = 1;
            make_a_move(n - 1, 0);
        } else {
            cout << "Bob" << endl;
        }
        while (true) {
            string cmd; cin >> cmd;
            int x, y; cin >> x >> y;
            if (cmd == "end") {
               if (x < 0) break;
               return 0;
            }
            if (cmd == "invalid") return 0;
            make_a_move(x, y, false);
            for (int j = offset, to = -1; j + 1 < n; j += 2) {
                if (a[j] ^ a[j + 1]) {
                    if (to == -1) {
                        to = (a[j] == 0 ? j : j + 1);
                    } else {
                        int from = (a[j] == 1 ? j : j + 1);
                        make_a_move(from, to);
                        break;
                    }
                }
            }
        }
    }
}
