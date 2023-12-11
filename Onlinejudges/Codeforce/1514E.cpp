#include <bits/stdc++.h>

using namespace std;

int ask(int u, int v) {
    cout << "1 " << u << ' ' << v << endl;
    int res; cin >> res; return res;
}

int ask(int u, const vector <int> &v) {
    cout << "2 " << u << ' ' << v.size();
    for (int w : v) cout << ' ' << w;
    cout << endl;
    int res; cin >> res; return res;
}

void answer(const vector <string> &ans) {
    cout << 3;
    for (const string &s : ans)
        cout << '\n' << s;
    cout << endl;
    int res; cin >> res;
    if (res < 0) exit(0);
}

void solve() {
    int N; cin >> N;
    vector <int> A(N);
    iota(A.begin(), A.end(), 0);
    stable_sort(A.begin(), A.end(),
    [](int u, int v) {
        return ask(u, v);     
    });
    vector <string> ans(N, string(N, '0'));
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            ans[A[i]][A[j]] = '1';
    int j = N - 2;
    for (int i = N - 1; i >= 0; i--) {
        if (j >= i) j = i - 1;
        if (j < 0) break;
        vector <int> v;
        for (int k = 0; k <= j; k++)
            v.push_back(A[k]);
        if (!ask(A[i], v)) continue;
        while (j > 0) {
            v.clear();
            for (int k = 0; k < j; k++)
                v.push_back(A[k]);
            if (ask(A[i], v)) j--;
            else break;
        }
        for (int k = j; k < i; k++)
            for (int l = i; l > k; l--)
                ans[A[l]][A[k]] = '1';
        j--;
    }
    answer(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}
