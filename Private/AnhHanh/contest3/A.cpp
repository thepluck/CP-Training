#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int pdiv[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    iota(pdiv, pdiv + MAXN, 0);
    for (int i = 2; i <= N; i++)
        if (pdiv[i] == i)
            for (int j = i; j <= N; j += i)
                pdiv[j] = i;
    vector <int> rem;
    vector <pair <int, int>> ans;
    for (int i = 2; i <= N / 2; i++)
        if (pdiv[i] == i) {
            vector <int> cur;
            for (int j = i; j <= N; j += i)
                if (pdiv[j] == i)
                    cur.push_back(j);
            if (cur.size() & 1) {
                rem.push_back(2 * i);
                cur.erase(find(cur.begin(),
                cur.end(), 2 * i));
            }
            for (int i = 0; i < cur.size(); i += 2)
                ans.emplace_back(cur[i], cur[i + 1]);
        }
    if (rem.size() & 1) rem.pop_back();
    for (int i = 0; i < rem.size(); i += 2)
        ans.emplace_back(rem[i], rem[i + 1]);
    cout << ans.size() << '\n';
    for (auto pp : ans)
        cout << pp.first << ' ' << pp.second << '\n';
}
