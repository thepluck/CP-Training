#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
const int MAX=1e6+2;
#define int long long
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll =long long;
ll c[2][MAX];

/**
 * Author: Stanford
 * Date: Unknown
 * Source: Stanford Notebook
 * Description: Min-cost max-flow. cap[i][j] != cap[j][i] is allowed; double edges are not.
 *  If costs can be negative, call setpi before maxflow, but note that negative cost cycles are not supported.
 *  To obtain the actual flow, look at positive values only.
 * Status: Tested on kattis mincostmaxflow, stress-tested against another implementation
 * Time: Approximately O(E^2)
 */
const ll INF = numeric_limits<ll>::max() / 4;

struct MCMF {
	int N;
	vector<vector <int>> ed, red;
	vector<vector <int>> cap, flow, cost;
	vector <int> seen;
	vector <int> dist, pi;
	vector<pair <int, int>> par;

	MCMF(int N) :
		N(N), ed(N), red(N), cap(N, vector <int>(N)), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, ll cap, ll cost, int dir) {
			ll val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (int i : ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			for (int i : red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
		rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
		return {totflow, totcost};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
				for (int to : ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

namespace dinic{
    #define eb emplace_back

    const int inf = INT_MAX;

    vector <int> dist, to, nxt, head;
    vector <int> flow, capa, work;
    int n, m; queue <int> q;

    void init(int n = 0) {
        dinic::n = n; m = 0;
        dist.assign(n + 5, 0);
        head.assign(n + 5, -1);
        work.assign(n + 5, 0);
        to.clear(); capa.clear();
        nxt.clear(); flow.clear();
    }

    int add_edge(int u, int v, int c, bool r = 0) {
        to.eb(v); capa.eb(c); flow.eb(0);
        nxt.eb(head[u]); head[u] = m++;
        to.eb(u); capa.eb(c * r); flow.eb(0);
        nxt.eb(head[v]); head[v] = m++;
        return m - 2;
    }

    bool bfs(int s, int t) {
        for (int i = 0; i <= n; i++)
            dist[i] = -1;
        dist[s] = 0; q.emplace(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; i >= 0; i = nxt[i])
                if (flow[i] < capa[i] && dist[to[i]] < 0) {
                    dist[to[i]] = dist[u] + 1;
                    q.emplace(to[i]);
                }
        }
        return dist[t] >= 0;
    }

    int dfs(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = nxt[i])
            if (flow[i] < capa[i] && dist[to[i]] == dist[s] + 1) {
                int d = dfs(to[i], t, min(f, capa[i] - flow[i]));
                if (d > 0) {
                    flow[i] += d; flow[i ^ 1] -= d; return d;
                }
            }
        return 0;
    }

    int max_flow(int s, int t) {
        int res = 0, aug;
        while (bfs(s, t)) {
            for (int i = 0; i <= n; i++)
                work[i] = head[i];
            while ((aug = dfs(s, t, inf)) > 0)
                res += aug;
        }
        return res;
    }
};

int n, m, k;

int id(int i, int j) {
    return (i - 1) * m + j;
}

const int dx[] = {-1, -1, 1, 1};
const int dy[] = {1, -1, 1, -1};
void test(){
    MCMF mc(100);
    mc.addEdge(0, 1, 5, 0);
    mc.addEdge(1, 3, 1, 0);
    mc.addEdge(1, 2, 4, 0);
    mc.addEdge(3, 2, 1, 0);
    cerr << mc.maxflow(0, 2).first;
}
signed main() {
#ifdef LightUpTheFire
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LightUpTheFire
    //test();return 0;
    cin >> n >> m >> k;
    /*if (n <= 20 && m <= 20) {
        MCMF cc(n * m + 5);
        dinic::init(n * m + 5);
        int tot = 0;
        int src = n * m + 1, sink = n * m + 2;
        for (int st = 1; st <= k; st++) {
            int i, j, x;
            cin >> i >> j >> x;
            tot += x;
            cc.addEdge(src, id(i, j), x, 0);
            dinic::add_edge(0, id(i, j), x);
        }
        if (tot % (n * m)) {
            cout << "-1\n"; return 0;
        }
        int wa=tot/(n*m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cc.addEdge(id(i, j), sink, wa, 0);
                cout<<id(i,j);
                for (int d = 0; d < 4; d++) {
                    int x = i + dx[d], y = j + dy[d];
                    if (x < 1 || x > n || y < 1 || y > m) continue;
                    cc.addEdge(id(i, j), id(x, y), tot, 1);
                    dinic::add_edge(id(i, j), id(x, y), tot);
                }
            }
        auto pppp = cc.maxflow(src, sink);
        cout<<tot<<' '<<pppp.first<<'\n';
        if (pppp.first < tot) {
            cout << "-1\n"; return 0;
        }
        cout << pppp.second; return 0;
    }*/
    ll dem=0,want,cnt=0;
    //cout<<-1;return 0;
    if(n==1 || m==1){
        int x,y,a,pre;
        for(int i=1;i<=k;i++) {
            cin>>x>>y;
            if (i == 1) cin >> pre;
            else {
                cin >> a;
                if (pre != a) {
                    cout << "-1"; return 0;
                }
            }

        }
        cout<<0;return 0;
        //for(int )
    }
   if(m<=2){
        swap(n,m);
        for(int i=1,x,y,a;i<=k;i++){
            cin>>y>>x>>a;
            c[x-1][y]+=a;
            cnt+=a*((y+x)&1);
            dem+=a;
        }
   }
   else {
        if(n>2){cout<<-1;return 0;}
        else{
            for(int i=1,x,y,a;i<=k;i++){
                cin>>x>>y>>a;
                c[x-1][y]+=a;
                cnt+=a*((y+x)&1);
                dem+=a;
            }
        }
   }
   if(dem%(n*m)!=0 || cnt*2!=dem) {cout<<-1;return 0;}
   want=dem/(n*m);
   ll ans=0;
    for(int i=1;i<=m;i++){
            c[0][i]+=c[1][i-1]-want;
            c[1][i]+=c[0][i-1]-want;
        ans+=abs(c[0][i])+abs(c[1][i]);
    }
    cout<<ans;
}
