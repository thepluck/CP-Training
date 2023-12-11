#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int C = 5e5 + 5;

class trie{
private:
    class node{
    public:
        int nxt[26], cnt[26]; bool has;

        node(): has(0){
            memset(cnt, 0, sizeof cnt);
        }
    };

    vector <node> data;

public:
    trie(){
        data.push_back(node());
    }

    void insert(const string &s){
        int pt = 0;
        for (char c : s){
            if (!data[pt].cnt[c - 'a']){
                data[pt].nxt[c - 'a'] = data.size();
                data.push_back(node());
            }
            data[pt].cnt[c - 'a']++;
            pt = data[pt].nxt[c - 'a'];
        }
        data[pt].has = 1;
    }

    void erase(const string &s){
        int pt = 0; bool flag = false;
        for (char c : s){
            data[pt].cnt[c - 'a']--;
            if (!data[pt].cnt[c - 'a']) flag = true;
            pt = data[pt].nxt[c - 'a'];
        }
        if (flag) data[pt].has = 0;
    }

    bool is_pref(const string &s){
        int pt = 0;
        for (char c : s){
            if (!data[pt].cnt[c - 'a']) return 0;
            pt = data[pt].nxt[c - 'a'];
        }
        return 1;
    }

    bool is_cover(const string &s){
        int pt = 0;
        for (char c : s){
            if (!data[pt].cnt[c - 'a']) return 0;
            pt = data[pt].nxt[c - 'a'];
            if (data[pt].has) return 1;
        }
        return 0;
    }
};

string a[N]; vector <trie> seg; vector <int> lo, hi;

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    for (int k = l; k <= r; k++) seg[i].insert(a[k]);
    if (l != r){
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
    }
}

void update(int i, int p, const string &s){
    if (lo[i] > p || hi[i] < p) return;
    seg[i].erase(a[p]); seg[i].insert(s);
    update(i * 2, p, s); update(i * 2 + 1, p, s);
}

bool is_pref(int i, int l, int r, const string &s){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r)
        return seg[i].is_pref(s);
    return is_pref(i * 2, l, r, s) || 
            is_pref(i * 2 + 1, l, r, s);
}

bool is_cover(int i, int l, int r, const string &s){
    if (lo[i] > r || hi[i] < l) return 0;
    if (lo[i] >= l && hi[i] <= r)
        return seg[i].is_cover(s);
    return is_cover(i * 2, l, r, s) || 
            is_cover(i * 2 + 1, l, r, s);
}

int main(){
    freopen("101628K.inp", "r", stdin);
    freopen("101628K.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n;
    for (int i = 1; i <= n; cin >> a[i++]);
    seg.resize(4 * n + 4, trie()); lo.resize(4 * n + 4);
    hi.resize(4 * n + 4); build(1, 1, n); cin >> q;
    while (q--){
        int cmd; cin >> cmd;
        if (cmd == 1){
            int p; string s; cin >> p >> s;
            update(1, p, s); a[p] = s;
        }
        if (cmd == 2){
            int l, r; string s; cin >> l >> r >> s;
            cout << (is_cover(1, l, r, s) ? "Y\n" : "N\n");
        }
        if (cmd == 3){
            int l, r; string s; cin >> l >> r >> s;
            cout << (is_pref(1, l, r, s) ? "Y\n" : "N\n");
        }
    }
}