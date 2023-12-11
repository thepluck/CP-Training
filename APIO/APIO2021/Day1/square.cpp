#include <bits/stdc++.h>

using namespace std;

bitset <2000000000> square;

bool solve(int N, int &a, int &b, int &c) {
    for (a = 0; a * a <= N; a++)
        for (b = a; b * b <= N - a * a; b++)
            if (square[N - a * a - b * b]) {
                c = sqrt(N - a * a - b * b);
                return true;
            }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long N; cin >> N;
    if (N == 1) return cout << "1\n1", 0;
    if (N == 2) return cout << "2\n1 1", 0;
    if (N == 3) return cout << "3\n1 1 1", 0;
    int a, b, c;
    for (int i = 0; i * i < 2e9; i++)
        square[i * i] = true;
    vector <int> ans;
    for (long long d = sqrt(N); d > 0; d--)
        if (solve(N - d * d, a, b, c)) {
            ans.push_back(d);
            if (a) ans.push_back(a);
            if (b) ans.push_back(b);
            if (c) ans.push_back(c);
            cout << ans.size() << '\n';
            for (int x : ans) cout << x << ' ';
            return 0;
        }
}
