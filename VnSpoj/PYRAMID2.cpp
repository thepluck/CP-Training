#include<cstdio>
#include<algorithm>
using namespace std;
 
char s[1000001]; int n;
 
int main() {
	scanf("%d%s",&n,s);
	int res = 0, delay = 0, cnt = 0, i;
	for(i = 0; i < n && s[i] == '<'; ++i);
	for(; i<n; ++i) 
		if(s[i] == '<') 
			res = max(res, delay++ + cnt);
		else {
			++cnt;
			if(delay > 0) --delay;
		}
	printf("%d\n", res);
	return 0;
}