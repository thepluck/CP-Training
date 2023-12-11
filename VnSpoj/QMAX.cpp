#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef const int& ci;
typedef long long ll;
const int oo = INT_MAX;
const int maxn = 5e4 + 10;
int node[maxn << 2] = {}, lazy[maxn << 2] = {};

void fastin(int& x){
	x = 0; bool neg = false;
	register int c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
	if (c == '-'){
		c = getchar(); neg = true;
	}
	for(; c > 47 && c < 58; c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}

void trueVal(ci i, ci lo, ci hi){
    if (lazy[i] == 0) return;
    node[i] += lazy[i];
    if (lo != hi){
        lazy[i << 1] += lazy[i];
        lazy[(i << 1) + 1] += lazy[i];
    }
    lazy[i] = 0;
}

void update(ci i, ci lo, ci hi, ci a, ci b, ci val){
    trueVal(i, lo, hi);
    if (lo > b || hi < a || lo > hi) return;
    if (lo >= a && hi <= b){
        node[i] += val;
        if (lo != hi){
            lazy[i << 1] += val;
            lazy[(i << 1) + 1] += val;
        }
        return;
    }
    int mi = (lo + hi) >> 1;
    update(i << 1, lo, mi, a, b, val);
    update((i << 1) + 1, mi + 1, hi, a, b, val);
    node[i] = max(node[i << 1], node[(i << 1) + 1]);
}

int get(ci i, ci lo, ci hi, ci a, ci b){
    trueVal(i, lo, hi);
    if (lo > b || hi < a || lo > hi) return -oo;
    if (lo >= a && hi <= b) return node[i];
    int mi = (lo + hi) >> 1;
    return max(get(i << 1, lo, mi, a, b), get((i << 1) + 1, mi + 1, hi, a, b));
}

int main(){
	int n, m; fastin(n); fastin(m);
	int u, v, val;
	while (m--){
		fastin(u); fastin(v);
		fastin(val);
		update(1, 1, n, u, v, val);
	}
	fastin(m);
	while (m--){
		fastin(u); fastin(v);
		cout << get(1, 1, n, u, v) << '\n';
	}
}
