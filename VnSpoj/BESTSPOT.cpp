#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define FOR(i, a, b, x) for (int i = (a); i x (b); ++i)
#define FORD(i, a, b, x) for (int i = (a); i x (b); --i)
#define task "bestspot"
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

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, 1 : 0;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, 1 : 0;
}

struct node{
    int v, w;
    bool operator < (const node &o) const {
        return w > o.w;
    }
};

heap <node> pq;
int n, m, nspot;
int dis[505][505];
vec <node> g[505];
bitset <505> avail;

void dijkstra(int s){
    for (int i = 1; i <= n; i++)
        dis[s][i] = inf;
    heap <node>().swap(pq);
    pq.push({s, 0}); dis[s][s] = 0;
    while (!pq.empty()){
        auto t = pq.top(); pq.pop();
        if (t.w > dis[s][t.v]) continue;
        for (auto e : g[t.v])
            if (dis[s][e.v] > dis[s][t.v] + e.w){
                dis[s][e.v] = dis[s][t.v] + e.w;
                pq.push({e.v, dis[s][e.v]});
            }
    }
    for (int i = 1; i <= n; i++)
        if (dis[s][i] == inf) avail[i] = true;
}

int main() {
    init(); //open();
    cin >> n >> nspot >> m;
    vec <int> spot(nspot);
    for (auto &x : spot) cin >> x;
    for (int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (auto x : spot) dijkstra(x);
    int best = inf, ans;
    for (int i = 1; i <= n; i++)
        if (!avail[i]){
            int cnt = 0;
            for (auto x : spot) cnt += dis[x][i];
            if (best > cnt){
                best = cnt;  ans = i;
            }
        }
    cout << ans << '\n';
}   