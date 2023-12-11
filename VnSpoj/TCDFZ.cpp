#include <cstdio>
using namespace std;
 
	
const int d[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
 
int last(int n){
	if (n < 10) return d[n];
	return (n % 100 / 10 & 1 ? 4 : 6) * last(n / 5) * last(n % 10) % 10;
}
 
int main(){
	int n; scanf("%d", &n);
	printf("%d", last(n));
	return 0;
} 