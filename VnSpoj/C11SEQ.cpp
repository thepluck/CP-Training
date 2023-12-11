#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define ub(v, x) upper_bound(all(v), (x)) - (v).begin()
 
typedef long long ll;
vector <ll> s, cp;
vector <int> bit;
int n; ll l, r;
 
void update(int i){
	for (; i <= n + 1; i += i & -i) 
		bit[i]++;
}
 
int get_num(int i){
	int res = 0;
	for (; i > 0; i -= i & -i)
		res += bit[i];
	return res;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l >> r; ll res = 0;
	s.assign(n + 1, 0);
	cp.assign(n + 1, 0);
	bit.assign(n + 2, 0);
	for (int i = 1; i <= n; i++){
		cin >> s[i]; 
		cp[i] = s[i] = s[i] + s[i - 1];
	}
	sort(cp.begin(), cp.end());
	cp.resize(unique(all(cp)) - cp.begin());
	for (int i = 0; i <= n; i++){
		res += get_num(ub(cp, s[i] - l));
		res -= get_num(ub(cp, s[i] - r - 1));
		update(ub(cp, s[i]));
	}
	cout << res;
	return 0;
}