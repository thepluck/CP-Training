#include <bits/stdc++.h>
using namespace std;

struct node{
    int val, id;
    bool operator < (const node &o) const {
        return val < o.val;
    }
};

struct edge{
    node *from, *to; int val;
    edge(): from(0), to(0){}
    edge(node *a, node *b): from(a), to(b){
        val = b->val - a->val;
    }
    bool operator < (const edge &o) const {
        return val > o.val;
    }
};

const int N = 1e5 + 5;
node a[N], b[N], c[N];
priority_queue <edge> pq;
int anc[N], rnk[N];

int find_set(int u){
    if (u != anc[u]) anc[u] = find_set(anc[u]);
    return anc[u];
}

bool union_set(int u, int v){
    u = find_set(u); v = find_set(v);
    if (u == v) return false;
    if (rnk[u] >= rnk[v]){
        anc[v] = u; rnk[u] += rnk[u] == rnk[v];
    }
    else anc[u] = v;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int n; cin >> n; a[n] = b[n] = c[n] = {-1, -1};
    for (int i = 0; i < n; i++){
        cin >> a[i].val >> b[i].val >> c[i].val;
        anc[i] = a[i].id = b[i].id = c[i].id = i;
    }
    sort(a, a + n); sort(b, b + n); sort(c, c + n);
    for (int i = 0; i < n - 1; i++){
        pq.push(edge(a + i, a + i + 1));
        pq.push(edge(b + i, b + i + 1));
        pq.push(edge(c + i, c + i + 1));
    }
    int vertexs = 1; long long res = 0;
    while (vertexs < n){
        auto cur = pq.top(); pq.pop();
        if (union_set(cur.from->id, cur.to->id)) 
            res += cur.val, vertexs++;
        if ((cur.to + 1)->val != -1)
            pq.push(edge(cur.from, cur.to + 1));
    }
    cout << res << '\n';
}