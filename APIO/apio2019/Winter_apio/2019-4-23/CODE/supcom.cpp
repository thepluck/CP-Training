#include<bits/stdc++.h>
#define int 			long long
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c) && c != '-');
	bool Minus = false; if (c == '-') { Minus = true; c = getchar(); }
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
	if (Minus) val = -val;
}
void Write(int val) {
	if (val < 0) putchar('-'), Write(-val);
	else if (val < 10) putchar('0' + val);
	else Write(val/10), putchar('0' + val%10);
}

struct ii {
	int first, second, third;
	ii() {}; ii(int first, int second, int third) : first(first), second(second), third(third) {};
};

const int N = 1e5 + 4, bs = 1e9+1e5+1; /// 2e9
int Next[N*33][2], Sum[N*33], Count[N*33], numNode;

bool BIT(int n, int k) { return n & (1LL<<k); } /// 1LL

void Insert(int val) {
	int fake = val + bs, curNode = 0;
	for (int i = 31; i >= 0; --i) {
		int bit = BIT(fake, i);
		if (Next[curNode][bit] == 0) Next[curNode][bit] = ++numNode;
		curNode = Next[curNode][bit]; 
		Count[curNode]++; Sum[curNode] += val;
	}
}

int getSum(int val) { /// < 
	int fake = val + bs, res = 0, curNode = 0;
	for (int i = 31; i >= 0; --i) {
		int bit = BIT(fake, i);
		if (bit == 1 && Next[curNode][0] != 0) res += Sum[ Next[curNode][0] ];
		if (Next[curNode][bit] == 0) break;
		curNode = Next[curNode][bit];
	}
	return res;
}

ii Find(int rank) {
	int curNode = 0, val = 0;
	for  (int i = 31; i >= 0; --i) {
		if (rank <= Count[ Next[curNode][0] ] && Next[curNode][0] != 0) curNode = Next[curNode][0];
		else {
			rank -= Count[ Next[curNode][0] ];
			curNode = Next[curNode][1];
			val += (1<<i);
		}
	}
	return ii(val-bs, curNode, rank);
}

main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("supcom.inp", "r")) {
		freopen("supcom.inp", "r", stdin);
		freopen("supcom.out", "w", stdout);
	}

	int T, L, R, type, p, q, val;

	Read(T);
	while (T--) {
		Read(type);
		if (type == 1) Read(val), Insert(val);
		else if (type == 2) {
			Read(L); Read(R);
			int res = getSum(R+1) - getSum(L);
			Write(res); putchar('\n');
		}
		else {
			Read(p); Read(q);
			ii tmp1 = Find(p);
			ii tmp2 = Find(q); 

			int L = tmp1.first, R = tmp2.first, nodeL = tmp1.second, nodeR = tmp2.second;
			int res = getSum(R+1) - getSum(L);
			// - (nodeL) * L - tmp2.second * R;
			res -= (tmp1.third - 1) * L;
			res -= (Count[tmp2.second] - tmp2.third) * R; 

				// cerr << "??? " << tmp1.second << " " << tmp2.second << '\n';

			Write(res); putchar('\n');

			Insert(L+1); Insert(R-1);
		}
	}

	return 0;
}