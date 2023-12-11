#include <bits/stdc++.h>

using namespace std;

string first[55], last[55];

int main() {
    freopen("bff.inp", "r", stdin);
    freopen("bff.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, res = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> first[i] >> last[i];
        for (int j = 0; j < i; j++) {
            if (first[i] == last[j]) res++;
            if (last[i] == first[j]) res++;
        }
    }
    cout << res;
}