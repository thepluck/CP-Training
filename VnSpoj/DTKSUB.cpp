#include <iostream>
#include <map>
#include <cstring>
using namespace std;

#define base 31ll
#define mod 1000009ll
const int N = 5e4 + 5;

typedef long long ll;

ll Hash[N], Pow[N];
int n, k;
char s[N];
int mp[mod];

typedef long long ll;

void build_hash(){
	Pow[0] = 1ll;
	for (int i = 1; i <= n; i++){
		Pow[i] = base * Pow[i - 1] % mod;
		Hash[i] = (base * Hash[i - 1] + s[i] - 'a' + 1) % mod; 
	}
}

ll get_hash(int i, int j){
	return (Hash[j] - Hash[i - 1] * Pow[j - i + 1] + mod * mod) % mod;
}

int main() {
	scanf("%d%d%s", &n, &k, s + 1);
	build_hash();
	int l = 0, r = n, m, ans;
	while (l <= r){
		memset(mp, 0, sizeof mp);
		m = (l + r) / 2;
		for (int i = 1; i <= n - m + 1; i++)
			if (++mp[get_hash(i, i + m - 1)] >= k){
				l = m + 1; ans = m; goto gg;
			}
		r = m - 1;
		gg:;
	}
	cout << ans;
	return 0;
}