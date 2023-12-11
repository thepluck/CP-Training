#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
typedef vector<int>vi;
typedef vector<vi>vvi;

struct IT{//0-indexed
    vi g, s;

    IT(int n){
        g.resize(n * 4);
        s.resize(n * 4);
    }

    int sz(){
        return g.size() / 4;
    }

    void inc(int L, int H, int val){
        update(1, 0, sz()-1, L, H, val);
    }

    int getMax(int L = 0, int H = 1e9){
        return query(1, 0, sz()-1, L, H);
    }

    void push(int x){
        g[x<<1] += s[x];
        s[x<<1] += s[x];
        g[x<<1|1] += s[x];
        s[x<<1|1] += s[x];
        s[x] = 0;
    }

    void update(int x, int L, int H, int u, int v, int val){
        if (v < L || H < u) return;
        if (u <= L && H <= v){
            g[x] += val;
            s[x] += val;
            return;
        }
        push(x);
        update(x<<1, L, (L+H>>1), u, v, val);
        update(x<<1|1, (L+H>>1)+1, H, u, v, val);
        g[x] = max(g[x<<1], g[x<<1|1]);
    }

    int query(int x, int L, int H, int u, int v){
        if (v < L || H < u) return 0;
        if (u <= L && H <= v) return g[x];
        push(x);
        int ans = max(query(x<<1, L, (L+H>>1), u, v),
                      query(x<<1|1, (L+H>>1)+1, H, u, v));
        g[x] = max(g[x<<1], g[x<<1|1]);
        return ans;
    }

};

struct Tree{//0-index
    vvi e;
    vvi b;
    vi d, F, L;
    vi sz, isHeavy, V;

    Tree(){}

    Tree(int n){
        e.resize(n);
        b.resize(32-__builtin_clz(n), vi(n));
        d = F = L = sz = isHeavy = vi(n);
    }

    void add(int x, int y){
        e[x].push_back(y);
        e[y].push_back(x);
    }

    void dfs(int x){
        F[x] = V.size();
        V.push_back(x);
        sz[x] = 1;
        int z = -1, maxSz = 0;
        for (int y : e[x]) if (y != b[0][x]){
            d[y] = d[x] + 1;
            b[0][y] = x;
            dfs(y);
            sz[x] += sz[y];
            if (sz[y] > maxSz){
                maxSz = sz[y];
                z = y;
            }
        }
        if (z != -1) isHeavy[z] = 1;
        L[x] = (int)V.size() - 1;        
    }

    bool isSupper(int c, int x){
        return F[c] <= F[x] && F[x] <= L[c];
    }

    int lca(int x, int y){
        if (isSupper(x, y)) return x;
        for (int i = b.size(); i--; ){
            if (!isSupper(b[i][x], y)) x = b[i][x];        
        }
        return b[0][x];
    }

    int jump(int x, int k){
        for (int i = b.size(); i--; ) if (k >> i & 1){
            x = b[i][x];
        }
        return x;
    }

    int nxt(int x, int y){
        if (isSupper(x, y)) return jump(y, d[y] - d[x] - 1);
        return b[0][x];
    }

    void build(){
        dfs(0);
        for (int i = 1; i < b.size(); ++i) for (int j = 0; j < e.size(); ++j){
            b[i][j] = b[i-1][b[i-1][j]];
        }        
    }
};

struct HeavyLight{
    Tree T;
    priority_queue<pair<int,int>> heap;
    vector<IT> its;
    vector<int> blockOf, posOf;

    HeavyLight(Tree &input){
        this->T = input;
        T.build();
        auto V = T.V;
        reverse(all(V));
        blockOf.assign(V.size(), -1);
        posOf.assign(V.size(), -1);
        for (int x : V) if (blockOf[x] == -1){
            int cnt = 0;
            for (int y = x; ; y = T.b[0][y]){
                blockOf[y] = its.size();
                posOf[y] = cnt++;
                if (y == 0 || !T.isHeavy[y]) break;
            }
            its.push_back(IT(cnt));
        }
    }

    void inc(int s, int t, int val){
        int c = T.lca(s, t);
        for (int x : {s, t}){
            if (x == t && t == c) break;
            if (x == t) c = T.nxt(c, x);
            while (1){
                int id = blockOf[x];
                if (blockOf[c] == id){
                    its[id].inc(posOf[x], posOf[c], val);
                    heap.push({its[id].getMax(), id});
                    break;
                }
                its[id].inc(posOf[x], its[id].sz(), val);
                heap.push({its[id].getMax(), id});
                x = T.jump(x, its[id].sz() - posOf[x]);
            }
        }
    }

    int getMax(){
        while (heap.size()){
            auto tmp = heap.top();
            if (tmp.first == its[tmp.second].getMax()) break;
            heap.pop();
        }
        if (heap.empty()) return 0;
        return heap.top().first;
    }

    void debug(){
        printf("===========================\n");
        for (int x = 0; x < T.V.size(); ++x){
            int id = blockOf[x], i = posOf[x];
            printf("cap[%d] = %d\n", x, its[id].getMax(i, i));
        }
    }

};

int32_t main(int32_t argc,char** argv){
    if (argc>1) freopen(argv[1],"r",stdin);
    if (argc>2) freopen(argv[2],"w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    Tree T(n);
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        T.add(x, y);
    }

    HeavyLight hld(T);
    while(m--){
        int v, s, t;
        cin >> v >> s >> t;
        --s, --t;
        hld.inc(s, t, 1 - 2 * v);
        // hld.debug();
        cout << hld.getMax() << '\n';
    }
}
