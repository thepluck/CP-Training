#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct manacher{
    vector <int> f;
    void build(const string &s){
        f.assign(2 * s.size() + 1, 0);
        string t; for (char c: s) t += '#', t += c;
        t += '#'; int n = t.size(), c(0), r(0);
        for (int i = 0; i < n; i++){
            f[i] = i < r ? min(r - i, f[2 * c - i]) : 0;
            while (i > f[i] && i + f[i] + 1 < n && 
            t[i - f[i] - 1] == t[i + f[i] + 1]) f[i]++; 
            if (i + f[i] > r){
                c = i; r = i + f[i];
            }
        }
    }
 
    bool is_palin(int i, int j){
        return f[i + j + 1] > j - i;
    }
};

vector <manacher> mn;
vector <string> vs;

int nxt[N][26], cnt[N], palin[N], sz;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; long long res = 0;
    mn.resize(n); vs.resize(n);
    for (auto &s : vs){
        int x; cin >> x >> s;
    }
    for (int i = 0; i < n; i++){
        mn[i].build(vs[i]); int pt = 0;
        for (int j = 0; vs[i][j]; j++){
            if (!nxt[pt][vs[i][j] - 'a']){
                nxt[pt][vs[i][j] - 'a'] = ++sz;
            }
            pt = nxt[pt][vs[i][j] - 'a'];
            if (mn[i].is_palin(j + 1, vs[i].size() - 1))
                palin[pt]++;
        }
        cnt[pt]++;
    }
    for (auto &s : vs) reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++){
        int pt = 0, j = 0;
        for (; vs[i][j] && nxt[pt][vs[i][j] - 'a']; j++){
            pt = nxt[pt][vs[i][j] - 'a'];
            if (j < vs[i].size() - 1 &&
                mn[i].is_palin(0, vs[i].size() - j - 2))
                res += cnt[pt];
        }
        if (j == vs[i].size()) res += palin[pt];
    }
    cout << res << '\n';
}