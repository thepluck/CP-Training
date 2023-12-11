#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define FOR(i, a, b, x) for (int i = (a); i x (b); ++i)
#define FORD(i, a, b, x) for (int i = (a); i x (b); --i)
#define task "MSE07B"
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

set <ii> s;

int main(){
    init(); //open();
    int cmd, prio, id;
    while (cin >> cmd){
        if (cmd == 0) return 0;
        if (cmd == 1){
            cin >> id >> prio;
            s.insert({prio, id});
        }
        if (cmd == 2){
            if (s.empty()) cout << "0\n";
            else {
                tie(prio, id) = *s.rbegin();
                cout << id << '\n';
                s.erase({prio, id});
            }
        }
        if (cmd == 3){
            if (s.empty()) cout << "0\n";
            else {
                tie(prio, id) = *s.begin();
                cout << id << '\n';
                s.erase({prio, id});
            }
        }
    }
}