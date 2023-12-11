#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, p; cin >> n >> p;
    vector <ii> s(n+1);
    s[0] = {0, 0}; int a;
    for (int i = 1; i <= n; i++){
        cin >> a; s[i] = {s[i-1].first + a,i};
    }
    sort(s.begin(), s.end());
    int res = 0, mini = n;
    for (int i = 0, j =- 1; i<=n; i++) {
        while (j < n && s[i].first - s[j + 1].first >= p) {
            mini = min(mini, s[++j].second);
        }
        if (j >= 0) {
            res = max(res, s[i].second - mini);
        }
    }
    if (res == 0) res = -1;
    cout << res;
    return 0;
}
