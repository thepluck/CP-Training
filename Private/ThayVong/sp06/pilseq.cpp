#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, x) for (int i = (a); i x (b); ++i)
#define FORD(i, a, b, x) for (int i = (a); i x (b); --i)
#define task "pilseq"
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
const int N = 1e6 + 5;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, 1 : 0;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, 1 : 0;
}

int t, n, a[N], b[N];
map <int, int> mp;

void res(int l, int r){
    if (l > r) return;
    int m = (l + r) / 2;
    res(l, m - 1); res(m + 1, r);
    swap(a[l], a[r]);
}

int main(){
    init(); open();
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n / 2; i++)
            b[i] = a[i + n / 2 + 1];
        for (int i = 1; i <= n / 2; i++)
            if (a[i] == b[i] || a[i + 1] == b[i]){
                cout << "NO"; goto gg;
            }
        cout << "YES";
        gg: cout << '\n';
    }
    return 0;
} 