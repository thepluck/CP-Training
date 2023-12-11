#include<bits/stdc++.h>
#define X			first
#define Y 			second
using namespace std;

typedef pair<int, int> ii;
typedef pair<long double, int> fi;
struct dataFlow {
	int u, v, cap, flow; long double cost;
	dataFlow() {}; 
	dataFlow(int u, int v, int cap, int flow, long double cost) : u(u), v(v), cap(cap), cost(cost), flow(flow) {};
};

const int N = 504;
const long double oo = (long double) 1e9 + 7;
int n, S, T;
ii a[N];

int sqr(int a) { return a*a; }
long double getDist(ii a, ii b) { return sqrt( sqr(a.X-b.X) + sqr(a.Y-b.Y) ); }

vector<dataFlow> lsEdge;
vector<int> adj[N];

void Add_Edge(int u, int v, int cap, long double cost) {
	lsEdge.push_back(dataFlow(u, v, cap, 0, cost));
	lsEdge.push_back(dataFlow(v, u, 0, 0, -cost));
	adj[u].push_back(lsEdge.size()-2);
	adj[v].push_back(lsEdge.size()-1);
}

priority_queue<fi, vector<fi>, greater<fi> > pq;
long double d[N];
int Trace[N];

bool Find_path() {
	for (int i = S; i <= T; ++i) d[i] = oo, Trace[i] = -1;
	d[S] = 0; pq.push(fi(d[S], S)); 
	while (pq.size()) {
		int u = pq.top().second; long double du = pq.top().first; 
		pq.pop();
		if (du != d[u]) continue;
		for (int id : adj[u]) {
			int v = lsEdge[id].v, cap = lsEdge[id].cap, flow = lsEdge[id].flow; 
			long double cost = lsEdge[id].cost;
			if (cap <= flow || d[v] <= du + cost) continue;
			d[v] = du + cost; Trace[v] = id;
			pq.push(fi(d[v], v));
		}
	}
	return Trace[T] != -1;
}

int maxFlow;
long double minCost;
 
void Fix_Graph() {
	int v = T, foo = (int) 1e9+7;
	while (v != S) {
		int id = Trace[v];
		int u = lsEdge[id].u, cap = lsEdge[id].cap, flow = lsEdge[id].flow;
		long double cost = lsEdge[id].cost;
		foo = min(foo, cap-flow);
		v = u;
	}

	v = T;
	while (v != S) {
		int id = Trace[v], u = lsEdge[id].u;
		lsEdge[id].flow += foo; lsEdge[id^1].flow -= foo;
		v = u;
	}

	maxFlow += foo;
	minCost += d[T] * foo;
}

int ans[N];

void sol() {
	S = 0; T = 2*n+1;
	for (int i = 1; i <= n; ++i) {
		Add_Edge(S, i, 1, 0);
		Add_Edge(i+n, T, 1, 0);	
	}

	for (int i = 1; i <= n; ++i) for (int j = i+1; j <= 2*n; ++j) {
		long double cost = getDist(a[i], a[j]);
		Add_Edge(i, j, 1, cost);
	}

	while (Find_path()) Fix_Graph();

	for (dataFlow edge : lsEdge) {
		int u = edge.u, v = edge.v, flow = edge.flow, cap = edge.cap;
		if (u == S || v == S || u == T || v == T || flow == 0 || cap == 0) continue;
		if (flow == 1) ans[u] = v-n;
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= 2*n; ++i) cin >> a[i].X >> a[i].Y;

	sol();

	return 0;
}