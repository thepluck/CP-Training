#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, x) for (int i = (a); i x (b); ++i)
#define FORD(i, a, b, x) for (int i = (a); i x (b); --i)
#define task "BIT2D"
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll ninfll = 0xc0c0c0c0c0c0c0c0;
const int N = 1030;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, 1 : 0;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, 1 : 0;
}

int bit[N][N], n;

void update(int i, int j, int val){
    for (int _i = i; _i <= n; _i += _i & -_i)
        for (int _j = j; _j <= n; _j += _j & -_j)
            bit[_i][_j] += val;
}

int get_val(int i, int j){
    int res = 0;
    for (int _i = i; _i > 0; _i -= _i & -_i)
        for (int _j = j; _j > 0; _j -= _j & -_j)
            res += bit[_i][_j];
    return res;
}

int get_rval(int l, int b, int r, int t){
    return get_val(r, t) + get_val(l - 1, b - 1) 
            - get_val(r, b - 1) - get_val(l - 1, t);
}

int main(){
    init(); //open();
    int cmd;
    while (cin >> cmd){
        if (cmd == 3) return 0;
        if (cmd == 0) cin >> n;
        if (cmd == 1){
            int x, y, val; cin >> x >> y >> val;
            update(x + 1, y + 1, val);
        }
        if (cmd == 2){
            int l, b, r, t;
            cin >> l >> b >> r >> t;
            cout << get_rval(l + 1, b + 1, r + 1, t + 1) << '\n';
        }
    }
    return 0;
}