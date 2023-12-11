#include <bits/stdc++.h>
using namespace std;

int n, x, cnt, nim;

int main(){
	int t; scanf("%d", &t);
	while (t--){
		cnt = nim = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			cnt += x == 1;
			nim ^= x;
		}
		if (cnt == n) cout << (n % 2 ? "Brother\n" : "John\n");
		else cout << (nim > 0 ? "John\n" : "Brother\n");
	}
	return 0;
}
