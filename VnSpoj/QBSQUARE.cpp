#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("qbsquare.inp", "r", stdin);
	//freopen("qbsquare.out", "w", stdout);
    int n, m; cin >> n >> m;	
	int a[m], b[n], la[m], lb[m], ra[m], rb[m], ta[m + 1], tb[m + 1];
	int topa, topb, ans = 0;
	bool v;
	memset(a, 0, sizeof a); memset(b, 0, sizeof b);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> v;
			if (v){a[j]++; b[j] = 0;}
			else{a[j] = 0; b[j]++;}
		}
		topa = 0; topb = 0;
		ta[topa] = -1; tb[topb] = -1;
		for (int j = 0; j < m; j++){
			while (topa > 0 && a[ta[topa]] >= a[j]) topa--;
			while (topb > 0 && b[tb[topb]] >= b[j]) topb--;
			la[j] = ta[topa] + 1; lb[j] = tb[topb] + 1;
			ta[++topa] = j; tb[++topb] = j;
		}
		topa = 0; topb = 0;
		ta[topa] = m; tb[topb] = m;
		for (int j = m - 1; j >= 0; j--){
			while (topa > 0 && a[ta[topa]] >= a[j]) topa--;
			while (topb > 0 && b[tb[topb]] >= b[j]) topb--;
			ra[j] = ta[topa] - 1; rb[j] = tb[topb] - 1;
			ta[++topa] = j; tb[++topb] = j;
		}
		for (int j = 0; j < m; j++){
			ans = max(ans, min(ra[j] - la[j] + 1, a[j]));
			ans = max(ans, min(rb[j] - lb[j] + 1, b[j]));
		}
	}
	cout << ans;
}