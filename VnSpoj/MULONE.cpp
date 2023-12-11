#include <cstdio>
#include <iostream>
using namespace std;
 
int n; char res[2000000];
 
void testcase() {
	scanf("%d", &n);
	int memo = 0, p = n+n-2;
	for(int i = 1; i <= n; ++i, --p) {
		memo += i;
		res[p] = memo % 10 + 0x30;
		memo /= 10;
	}
	for(int i = n-1; i > 0; --i, --p) {
		memo += i;
		res[p] = memo % 10 + 0x30;
		memo /= 10;
	}
	if(memo) printf("%d", memo);
	res[n+n-1] = 0; printf("%s\n", res);
}
 
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) testcase();
	return 0;
}