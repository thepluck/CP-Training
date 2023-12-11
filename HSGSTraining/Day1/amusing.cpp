#include <bits/stdc++.h>
using namespace std;

long long dp[100][100];
int digit1[100], digit2[100], cnt1, cnt2;

long long rec(int tot, int pos, bool f1, bool f2) {
	if (pos >= tot) return 1;
	if (pos >= cnt2 && f2) return tot == cnt2;
	if (!f1 && !f2 && ~dp[tot][pos])return dp[tot][pos];
	int lim = 9;
	if (f1) lim = min(lim, digit1[tot - 1 - pos]);
	if (f2) lim = min(lim, digit2[cnt2 - 1 - pos]);
	long long ans = 0;
	for (int i = 0; i <= lim; i++) {
		if (!pos && !i) continue;
		ans += rec(tot, pos+1,
        f1 && i == digit1[tot - 1 - pos],
        f2 && i == digit2[cnt2 - 1 - pos]);
	}
	if(!f1 && !f2) dp[tot][pos] = ans;
	return ans;
}

long long calc(long long n,long long k) {
	cnt1 = cnt2 = 0;
	while (n) {
		digit1[cnt1++] = n % 10; n /= 10;
	}
	while (k) {
		digit2[cnt2++] = k % 10; k /= 10;
	}
	long long ans = 0;
	for(int i = 1; i <= cnt1; i++)
		ans += rec(i, 0, i == cnt1, 1);
	return ans;
}

int main() {
    freopen("amusing.in", "r", stdin);
    freopen("amusing.out", "w", stdout);
    int k, m; cin >> k >> m;
    memset(dp, -1, sizeof(dp));
	long long ans = 0, l = k;
	long long r = 1000000000000000000ll;
	while(l <= r) {
		long long mid = (l + r) / 2;
		long long tmp = calc(mid, k);
		if (tmp == m) ans = mid;
		if (tmp >= m) r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << '\n';
}