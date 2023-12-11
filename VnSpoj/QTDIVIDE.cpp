
// Problem : One piece
// Contest : SPOJ - Classical
// URL : https://www.spoj.com/problems/QTDIVIDE/
// Memory Limit : 1536 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

struct double_coin {
    int a, b, i;
    
    bool operator <
    (const double_coin &o) const {
        return a < o.a;
    }
};

struct single_coin {
    int v, i;
    
    bool operator <
    (const single_coin &o) const {
        return v < o.v;
    }
};

const int N = 5e5 + 5;

double_coin a[N]; bool mark[N];
priority_queue <single_coin> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].i = i; cin >> a[i].a;
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i].b;
    sort(a + 1, a + n + 1);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        pq.push({a[i].b, i});
        if (i & 1) {
            auto t = pq.top(); pq.pop();
            res += t.v; mark[t.i] = 1;
        }
    }
    cout << res << '\n';
    stack <int> wait;
    for (int i = 1; i <= n; i++)
        if (mark[i]) wait.push(a[i].i);
        else {
            cout << a[i].i << ' ';
            cout << wait.top() << '\n';
            wait.pop();
        }
}