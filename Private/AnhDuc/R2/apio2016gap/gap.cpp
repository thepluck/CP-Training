#include "gap.h"
#include <bits/stdc++.h>

using namespace std;

long long findGap(int t, int n) {
	long long lo, hi, res;
	MinMax(0, 1000000000000000000ll, &lo, &hi);
	if (t == 1) {
		res = 0;
		for (int i = 1; i < (n + 1) / 2; i++) {
			long long mn, mx;
			MinMax(lo + 1, hi - 1, &mn, &mx);
			res = max(res, mn - lo);
			res = max(res, hi - mx);
			lo = mn; hi = mx;
		}
		res = max(res, hi - lo);
		return res;
	}
	else {
		res = (hi - lo - 1) / (n - 1) + 1;
		long long step = res, pre = lo;
		while (lo < hi) {
			long long mn, mx;
			MinMax(lo, lo + res - 1, &mn, &mx);
			lo += res; if (mn == -1) continue;
			res = max(res, mn - pre); pre = mx;
		}
		return res;
	}
}
