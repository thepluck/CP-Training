#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int encode(const string &s) {
    int res = 0;
    for (char c : s)
        res = res * 4 + c - 'A';
    return res;
}

pair <int, int> tr[1 << 16][22];
int dis[1 << 16][22];
int vs[1 << 16][22], cc;
string t[4]; int tim, n, sign;
vector <int> ans; bool ok = 1;

void rec1(int l, int r) {
    if (!ok) return;
    if (r - l == 14) {
        //12 9 4 8 2 13 
        ans.push_back((l + 12) * sign + cc);
        ans.push_back((l + 9) * sign + cc);
        ans.push_back((l + 4) * sign + cc);
        ans.push_back((l + 8) * sign + cc);
        ans.push_back((l + 2) * sign + cc);
        ans.push_back((l + 13) * sign + cc);
        return;
    }
    if (r - l == 12) {
        //10 5 8 2 11 
        ans.push_back((l + 10) * sign + cc);
        ans.push_back((l + 5) * sign + cc);
        ans.push_back((l + 8) * sign + cc);
        ans.push_back((l + 2) * sign + cc);
        ans.push_back((l + 11) * sign + cc);
        return;
    }
    if (r - l == 10) {
        //8 5 2 9
        ans.push_back((l + 8) * sign + cc);
        ans.push_back((l + 5) * sign + cc);
        ans.push_back((l + 2) * sign + cc);
        ans.push_back((l + 9) * sign + cc);
        return;
    }
    if (r - l == 8) {
        //3 6 1 7 
        ans.push_back((l + 3) * sign + cc);
        ans.push_back((l + 6) * sign + cc);
        ans.push_back((l + 1) * sign + cc);
        ans.push_back((l + 7) * sign + cc);
        return;
    }
    if (r - l == 6) {
        ok = 0; return;
    }
    if (r - l == 4) {
        ok = 0; return;
    }
    if (r - l == 2) return;
    ans.push_back((r - 2) * sign + cc);
    ans.push_back((l + 5) * sign + cc);
    rec1(l + 4, r - 4);
    ans.push_back((l + 2) * sign + cc);
    ans.push_back((r - 1) * sign + cc);
}

void rec2(int l, int r) {
    if (r - l == 2) return;
    if (r - l == 6) {
        ans.push_back(l + 3);
        return;
    }
    ans.push_back(r - 3);
    ans.push_back(l + 5);
    rec2(l + 4, r - 4);
}

void solve() {
    tim++; int p; sign = 1; cc = 0;
    queue <pair <string, int>> q;
    string s; cin >> s; n = s.size();
    t[0] = t[1] = t[2] = t[3] = "";
    for (char c : s)
        switch (c) {
            case 'A' : t[0] += c; break;
            case 'B' : t[1] += c; break;
            case 'C' : t[2] += c; break;
            case 'D' : t[3] += c; break;
        }
    if (n <= 8) {
        q.emplace(s, 0);
        dis[encode(s)][0] = 0;
        tr[encode(s)][0] = {-1, -1};
        vs[encode(s)][0] = tim;
        
        while (q.size()) {
            tie(s, p) = q.front(); q.pop();
            int cur = encode(s);
            s.insert(p, "  ");
            for (int i = 0; i < n + 1; i++) {
                if (i == p - 1 ||i == p
                || i == p + 1) continue;
                string x = s;
                x[p] = x[i]; x[p + 1] = x[i + 1];
                x[i] = x[i + 1] = ' ';
                x.erase(i, 2);
                int code = encode(x);
                if (vs[code][i] != tim) {
                    vs[code][i] = tim;
                    dis[code][i] = dis[cur][p] + 1;
                    tr[code][i] = {cur, p};
                    q.emplace(x, i);
                }
            }
        }
        int step = INT_MAX, res;
        do {
            s = t[0] + t[1] + t[2] + t[3];
            int cur = encode(s);
            if (vs[cur][0] == tim)
                if (dis[cur][0] < step) {
                    step = dis[cur][0];
                    res = cur;
                }
        }
        while (next_permutation(t, t + 4));
        if (step > n + 2) {
            cout << "-1\n"; return;
        }
        else {
            p = 0; ans.clear();
            while (~tr[res][p].first) {
                ans.push_back(p);
                tie(res, p) = tr[res][p];
            }
            cout << ans.size() << ' ';
            for (int i = ans.size() - 1;
            ~i; i--) cout << ans[i] + 1 << ' ';
            cout << '\n';
        }
        return;
    }
    
    if (t[2].empty() || t[0].empty()) {
        ans.clear(); ok = 1; rec1(0, n + 2);
        if (!ok) {
            cout << "-1\n"; return;
        }
        for (int i = n - 1; i > 0; i -= 2)
            ans.push_back(i);
        cout << ans.size() << ' ';
        for (int x : ans)
            cout << x << ' ';
        cout << '\n'; return;
    }
    ans.clear();
    ok = 1; rec2(0, n + 2);
    for (int i = n / 2; i < n; i += 2)
        ans.push_back(i + 3);
    sign = -1;
    cc = n + 2;
    rec1(0, n / 2 + 2);
    cc = n / 2 + 2;
    rec1(0, n / 2 + 2);
    if (!ok) {
        cout << "-1\n"; return;
    }
    cout << ans.size() << ' ';
    for (int x : ans)
        cout << x << ' ';
    cout << '\n';
}

int main() {
    freopen("boxgame.inp", "r", stdin);
    freopen("boxgame.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}