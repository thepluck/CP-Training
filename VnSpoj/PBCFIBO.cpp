	
#include <iostream>
#include <map>
using namespace std;
 
typedef pair<int,int> PII;
 
map<PII,int> ma;
long long S, N;
int K;
long long C[10000];
int F[100000];
 
int main() {
	cin >> N >> K >> S;
	int a = 1 % K, b = 2 % K, dem = 2;
	C[a] ++ ;
	F[1] = a;
	F[2] = b;
	while(!ma.count(PII(a,b)) && dem <= N) {
		ma[PII(a,b)] = dem;
		C[b] ++ ;
		int z = (a + b) % K;
		a = b;
		b = z;
		++dem;
		F[dem] = b;
	}
	if(dem<=N) {
		int ct = dem - ma[PII(a,b)];
		int pd = dem;
		long long lap = (N - pd) / ct;
		for(int i=pd;i<pd+ct && i<=N;++i) {
			C[F[i-ct]] += lap;
			if(i-pd <= (N-pd) % ct)
				++C[F[i-ct]];
		}
	}
	long long total = 0;
	for(int i=0;i<10000;++i) {
		total += C[i];
		if(total >= S) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}