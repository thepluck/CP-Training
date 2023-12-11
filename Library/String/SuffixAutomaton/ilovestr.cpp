#include <bits/stdc++.h>
using namespace std;

struct suffix_automaton{
    using ii = pair <int, int>;
    #define fi first
    #define se second
    struct state{
        int len, link;
        map <char, int> nxt;
        int& operator [] (const char &c){
            return nxt[c];
        }
    };

    static const int N = 2e6 + 5;
    state st[N << 1]; 
    int sz = 0, last, dp[N << 1], cnt[N << 1];
    vector <ii> order;

    suffix_automaton(){
        memset(dp, -1, sizeof dp);
    }

    void clear(){
        st[0].len = 0; st[0].link = -1;
        sz++; last = 0; dp[0] = -1;
        st[0].nxt.clear(); order.clear();
    }

    void extend(char c){
        int cur, p = last, q, cl;
        cnt[cur = sz++] = 1;
        st[cur].len = st[last].len + 1;
        order.push_back({st[cur].len, cur});
        while (p != -1 && !st[p].nxt.count(c)){
            st[p][c] = cur; p = st[p].link;
        }
        if (p == -1) st[cur].link = 0;
        else {
            q = st[p][c];
            if (st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else {
                st[cl = sz++].nxt = st[q].nxt;
                st[cl].link = st[q].link;
                st[cl].len = st[p].len + 1;
                order.push_back({st[cl].len, cl});
                while (p != -1 && st[p][c] == q){
                    st[p][c] = cl; p = st[p].link;
                }
                st[q].link = st[cur].link = cl;
            }
        }
        last = cur;
    }

    int dfs(int cur){
        if (dp[cur] != -1) return dp[cur];
        for (auto it : st[cur].nxt)
            dp[cur] += dfs(it.se);
        return dp[cur] = dp[cur] + 2;
    }

    void init(const string &s, bool need = 0){
        clear(); for (char c : s) extend(c);
        if (need){
            sort(order.rbegin(), order.rend());
            for (auto pp : order)
                cnt[st[pp.se].link] += cnt[pp.se];
        }
    }

    int lcs(const string &s, const string &t){
        init(s); int l = 0, p = 0, ans = 0;
        for (int i = 0; t[i]; i++){
            while (p && !st[p].nxt.count(t[i])){
                p = st[p].link; l = st[p].len;
            }
            if (st[p].nxt.count(t[i])){
                p = st[p][t[i]]; l++;
            }
            ans = max(ans, l);
        }
        return ans;
    }

    int count(const string &t){
        int p = 0;
        for (char c : t){
            if (!st[p].nxt.count(c)) return 0;
            p = st[p][c];
        }
        return cnt[p];
    }
} sa;

void solve(){
    string s; cin >> s; sa.init(s, 1);
    int q; cin >> q;
    while (q--){
        cin >> s;
        cout << (sa.count(s) ? "y\n" : "n\n");
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
}