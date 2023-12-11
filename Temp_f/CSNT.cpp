#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define mset(x, i) memset(x,i,sizeof(x))
#define elif else if
#define heap priority_queue
#define fi first
#define se second
#define pb push_back
#define ld long double
#define ll long long
#define ull unsigned long long
#define task "CSNT"
using namespace std;

int typetest;
template<class T>
void read(T &x){
    register int c;
    T neg = 1;
    x = (T)0;
    while ((c = getchar()) <= 47 || c >= 58)
		if(c == '-') neg = -1;
    for (; (c > 47 && c < 58); c = getchar()){
        x = (x << 3) + (x << 1) + (T)(c - 48);
    }
	x *= neg;
}
inline void fastIOfileinput(){
	ios_base:: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen(task".INP", "r", stdin);
	freopen(task".OUT", "w", stdout);
//	freopen(task".in", "r", stdin);
//	freopen(task".out", "w", stdout);
	typetest = 0;
}

const int N = 1e6 + 2;
int n, m;
int f[N];
bool ck[N];

void ethoras(int n){
	m = 0;
	int i;
	for(i = 2; i * i <= n; ++i){
		if(!ck[i]){
			for(int j = i * i; j <= n; j += i)
				ck[j] = 1;
			f[++m] = i;
		}
	}
	for(; i <= n; ++i)
		if(!ck[i])
			f[++m] = i;
}

void Enter(){
	read(n);
}

int rev(int v){
	int u = 0;
	while(v){
		u = u * 10 + (v % 10);
		v /= 10;
	}
	return u;
}
bool check(int v){
	if(v == 2)
		return true;
	if(v < 2 || !(v & 1))
		return false;
	for(int i = 3; i * i <= v; i += 2)
		if(v % i == 0)
			return false;
	return true;
}

void solve(){
	ethoras(n);
	int cnt = 0;
	vector<pair<int, int> > s;
	for(int i = 1; i <= m; ++i){
		int v = rev(f[i]);
//		cout << f[i] << " " << v << "\n";
		if(v != f[i] && check(v) )
			++cnt,s.pb({f[i], v});
	}
	cout << cnt << "\n";
	for(int i = 0; i < s.size(); ++i)
		cout << s[i].first << " " << s[i].se << "\n";
}

signed main(){
	fastIOfileinput();
	if(typetest){
		int t;
		cin >> t;
		while(t--){
			Enter();
			solve();
		}
	}
	else{
		Enter();
		solve();
	}
}