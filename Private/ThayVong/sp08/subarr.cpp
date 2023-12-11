#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define FOR(i, a, b, x) for (int i = (a); i x (b); ++i)
#define FORD(i, a, b, x) for (int i = (a); i x (b); --i)
#define task "subarr"
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

const int N = 4e5 + 5;
int a[N], cnt[N];
ii cmp[N];

int main(){
    init(); //open();
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; cmp[i] = {a[i], i};
    }
    sort(cmp + 1, cmp + n + 1);
    a[cmp[1].second] = 1;
    for (int i = 2; i <= n; i++)
        if (cmp[i].first == cmp[i - 1].first)
            a[cmp[i].second] = a[cmp[i - 1].second];
        else a[cmp[i].second] = a[cmp[i - 1].second] + 1;
    cnt[0] = 1; ll ans = 0;
    for (int i = 1, cur = (k == 1), j = 0; i <= n; i++){
        cur -= --cnt[a[i - 1]] == k - 1;
        while (j < n && cur == 0)
            cur += ++cnt[a[++j]] == k;
        if (cur > 0) ans += n - j + 1;
    }
    cout << ans << '\n';
}