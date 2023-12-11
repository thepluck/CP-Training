#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define FOR(i, a, b, x) for (int i = (a); i x (b); ++i)
#define FORD(i, a, b, x) for (int i = (a); i x (b); --i)
#define task "kmin"
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

struct num{
    int val, x, y;
    bool operator < (const num &o) const {
        return val > o.val;
    }
};
heap <num> pq;

int main(){
    init(); //open();
    int k, n, m;
    cin >> n >> m >> k;
    vec <int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(all(a)); sort(all(b));
    for (int i = 0; i < m; i++)
        pq.push({a[0] + b[i], 0, i});
    while (k > 0){
        cout << pq.top().val << '\n';
        int x = pq.top().x, y = pq.top().y;
        pq.pop(); k--;
        if (x + 1 < n) pq.push({a[x + 1] + b[y], x + 1, y});
    }
}