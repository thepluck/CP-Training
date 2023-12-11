#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define FOR(i, a, b, x) for (int i = (a); i x (b); ++i)
#define FORD(i, a, b, x) for (int i = (a); i x (b); --i)
#define task "pwrfail"
#define popcnt __builtin_popcountll
#define ctz __builtin_ctzll
#define clz __builtin_clzll
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void open(){
    //freopen("input.txt", "r", stdin);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}

using uint = unsigned int;
using ll = long long;
using ull = unsigned ll;
using ii = pair <int, int>;

template <class T>
using vec = vector <T>;
template <class T>
using vec2d = vec <vec <T>>;
template <class T>
using vec3d = vec <vec2d <T>>;

template <class key, class cmp = less <key>>
using heap = priority_queue <key, vec <key>, cmp>;

mt19937 rng(steady_clock::now().time_since_epoch().count());
const int inf = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll ninfll = 0xc0c0c0c0c0c0c0c0;
const double rinf = 1e20;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, 1 : 0;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, 1 : 0;
}

struct node{
    int v; double dis;
    bool operator < (const node& o) const {
        return dis > o.dis;
    }
};

heap <node> pq;
complex <double> pt[1001];
vec <node> g[1001];
double dist[1001][1001];
double dis[1001];
int n, w; double m;

void dijkstra(){
    pq.push({1, 0}); 
    for (int i = 1; i <= n; i++) 
        dis[i] = rinf;
    dis[1] = 0;
    while (!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        if (tmp.dis > dis[tmp.v]) continue;
        if (tmp.v == n) return;
        for (auto e : g[tmp.v])
            if (dis[e.v] > dis[tmp.v] + e.dis){
                dis[e.v] = dis[tmp.v] + e.dis;
                pq.push({e.v, dis[e.v]});
            }
    }
}

int main(){
    init(); //open();
    cin >> n >> w >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = rinf;
    for (int i = 1; i <= n; i++){
        int u, v; cin >> u >> v;
        pt[i] = {u, v};
    }
    for (int i = 1, u, v; i <= w; i++){
        cin >> u >> v;
        dist[u][v] = dist[v][u] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            if (dist[i][j] != 0 && abs(pt[i] - pt[j]) <= m) 
                dist[i][j] = abs(pt[i] - pt[j]);
            if (dist[i][j] != rinf) g[i].push_back({j, dist[i][j]});
        }
    dijkstra();
    if (dis[n] != rinf)
        cout << ll(dis[n] * 1000ll) << '\n';
    else cout << "-1\n";
}