#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, x) for (int i = (a); i x (b); ++i)
#define FORD(i, a, b, x) for (int i = (a); i x (b); --i)
#define task "lightroad"
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
const int N = 1e5 + 5;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, 1 : 0;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, 1 : 0;
}

char s[N]; 
int n, cnt[256];
double ans = 26;

ii calc(int num){
    memset(cnt, 0, sizeof cnt); 
    --num; cnt[0] = 1; int st, en; st = 0; en = -1;
    for (int i = 1, k = 0; i <= n; i++){
        if (--cnt[s[i - 1]] == 0) num++;
        while (k < n && num > 0) 
            num -= ++cnt[s[++k]] == 1;
        while (k < n && cnt[s[k + 1]] > 0) ++cnt[s[++k]];
        if (num > 0) break;
        if (en - st < k - i) en = k, st = i;
    }
    return {st, en};
}

int main(){
    init(); //open();
    cin >> n; scanf("%s", s + 1); ii res;
    for (int num = 1, st, en; num <= 26; num++){
        tie(st, en) = calc(num);
        if (en - st + 1 == 0) break;
        if (ans > 1.0 * num / (en - st + 1)){
            ans = 1.0 * num / (en - st + 1);
            res = {st, en};
        }
    }
    cout << res.first << ' ' << res.second << '\n';
}