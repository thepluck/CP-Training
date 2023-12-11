#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;
const int N = 300005;
ll bit[N], qv[N], reqd[N];
int ql[N], qr[N], lo[N], hi[N], n, m, q;
vector <int> own[N], check[N];

void update(int i, ll val){
    for (; i <= m; i += i & -i) bit[i] += val;
}

void update(int l, int r, ll val){
    if (l <= r){
        update(l, val); update(r + 1, -val);
    }
    else {
        update(1, val); update(r + 1, -val);
        update(l, val); update(m + 1, -val);
    }
}

ll get_val(int i){
    ll res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, x; i <= m; i++){
        cin >> x; own[x].eb(i);
    }
    for (int i = 1; i <= n; i++) cin >> reqd[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
        cin >> ql[i] >> qr[i] >> qv[i];
    for (int i = 1; i <= n; i++){
        lo[i] = 1; hi[i] = q + 1;
    }
    while (true){
        for (int i = 0; i <= m; i++) bit[i] = 0;
        bool flag = false;
        for (int i = 1; i <= n; i++)
            if (lo[i] != hi[i]){
                flag = true;
                check[(lo[i] + hi[i]) >> 1].eb(i);
            }
        if (!flag) break;
        for (int i = 1; i <= q; i++){
            update(ql[i], qr[i], qv[i]);
            while (!check[i].empty()){
                int id = check[i].back();
                check[i].pop_back();
                ll sum = 0;
                for (auto sec : own[id]){
                    sum += get_val(sec);
                    if (sum >= reqd[id]) break;
                }
                if (sum >= reqd[id]) hi[id] = i;
                else lo[id] = i + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (lo[i] <= q) cout << lo[i] << '\n';
        else cout << "NIE\n";
    }
}