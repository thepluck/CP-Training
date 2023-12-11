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

    static const int N = 250005;
    state st[N << 1];
    int sz = 0, last, dp[N << 1], cnt[N << 1];
    vector <ii> order;

    suffix_automaton(){
        memset(dp, -1, sizeof dp);
    }

    void init(){
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

    int total(int cur = 0){
        if (dp[cur] != -1) return dp[cur];
        for (auto it : st[cur].nxt)
            dp[cur] += total(it.se);
        return dp[cur] = dp[cur] + 2;
    }

    void build(const string &s, bool need_cnt = 0){
        init(); for (char c : s) extend(c);
        if (need_cnt){
            sort(order.rbegin(), order.rend());
            for (auto pp : order)
                cnt[st[pp.se].link] += cnt[pp.se];
            cnt[0] = 0;
        }
    }

    int lcs(const string &s, const string &t){
        build(s); int l = 0, p = 0, ans = 0;
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

    string lexi(int k){
        string res; int p = 0; k++;
        while (k-- > 1){
            for (auto it : st[p].nxt){
                if (k > dp[it.se])
                    k -= dp[it.se];
                else {
                    res.push_back(it.fi);
                    p = it.se; break;
                }
            }
        }
        return res;
    }
} sa;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; int q, k; cin >> s >> q; 
    sa.build(s); sa.total();
    while (q--){
        cin >> k;
        cout << sa.lexi(k) << '\n';
    }
}