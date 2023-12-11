#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 + 10;
int s[maxn];
bitset <maxn> av;
 
int main(){
	av.set(); int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", s + i); s[i] += s[i - 1];
	}
	for (int i = 1, mins = s[n]; i <= n; i++){
		av[i] = av[i] & (s[i - 1] < mins);
		mins = min(mins, s[i] + s[n]);
	}
	for (int i = n, mins = s[n]; i > 0; i--){
		av[i] = av[i] & (s[i - 1] < mins);
		mins = min(mins, s[i - 1]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += av[i];
	printf("%d", cnt);
	return 0;
}