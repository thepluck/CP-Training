#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
	int n = code.size() + 2;
	vector<int> degree(n, 1);
	for (int i : code)
		degree[i]++;

	int ptr = 0;
	while (degree[ptr] != 1)
		ptr++;
	int leaf = ptr;

	vector<pair<int, int>> edges;
	for (int v : code) {
		edges.emplace_back(leaf, v);
		if (--degree[v] == 1 && v < ptr) {
			leaf = v;
		} else {
			ptr++;
			while (degree[ptr] != 1)
				ptr++;
			leaf = ptr;
		}
	}
	edges.emplace_back(leaf, n-1);
	return edges;
}

vector<int> array_gen(int n, int L, int R) {
	vector<int> res(n);
	for (auto &v : res) v = rnd.next(L, R);
	return res;
}

vector<vector<int>> array2d_gen(int n, int m, int L, int R) {
	vector<vector<int>> res(n);
	for (auto &v : res) v = array_gen(m, L, R);
	return res;
}

vector<pair<int, int>> tree_gen(int n) { // 0 index
	return pruefer_decode(array_gen(n - 2, 0, n - 1));
}

vector<int> part_small(int m, int n) {
	vector<int> s = rnd.partition(m + 1, n, 2);
	s.erase(s.end()); return s;
}

vector<int> part(int m, int n) {
	vector<int> s = part_small(m, n);
	while ((int) set<int>(s.begin(), s.end()).size() != m) {
		s = part_small(m, n);
	}
	return s;
}

int q[5005], w[5005], c[5005];

signed main(int32_t argc, char *argv[]) {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	registerGen(argc, argv, 1);

	string sub = argv[2];
	
	int n, s;
	
	if (sub == "N=500,Q=500") {
		n = rnd.next(498, 500), s = rnd.next(498, 500);
	} else {
		n = rnd.next(4998, 5000), s = rnd.next(4998, 5000);
	}

	auto gen_w = [&]() -> int {
		int chance = rnd.next(0, 10), w = rnd.wnext(1, min(2 * s, 5000), 1);
		if (chance <= 3) {
			w = rnd.next(1, (int) sqrt(s));
		}
		return w;
	};
	
	vector<pair<int, int>> tree;
	vector<vector<int>> adj(n + 1);
	
	if (sub == "Q=1,STAR" || sub == "STAR") {
		for (int i = 2; i <= n; i++)
			tree.emplace_back(0, i - 1);
	} else {
		tree = tree_gen(n);
	}
	
	for (auto [x, y] : tree) {
	    adj[x + 1].push_back(y + 1);
	    adj[y + 1].push_back(x + 1);
      
	}
  
	vector<double> coeff(n);
	for (int i = 0; i < n; i++)
	    if (rnd.next(2)) coeff[i] = rnd.next(0.001, 1.0);
	    else coeff[i] = rnd.next(1.0, 1000.0);
	 
	sort(coeff.begin(), coeff.end());
	int cur = 0;
	
	vector<int> cand(1, 1);
	
	vector<int> par(n + 1);
	
	vector<double> dcm(n + 1);
	
	while (cand.size()) {
	    int i = rnd.next(cand.size());
	    int u = cand[i];
	    cand.erase(cand.begin() + i);
	    dcm[u] = coeff[cur++];
	    for (int v : adj[u])
	        if (v != par[u]) {
	            par[v] = u; cand.push_back(v);
	        }
	}


	cout << n << ' ' << s << '\n';
	for (int i = 1; i <= n; i++) {
		q[i] = rnd.next(1, 5000), w[i] = gen_w(), c[i] = rnd.next(1, (int) 1e6);
		if (sub == "Q=1,STAR") q[i] = 1;
		else if (sub == "Q=1") q[i] = 1;
		else if (sub == "Q=1,W=1") q[i] = w[i] = 1;
    else if (rnd.next(10)) {
      w[i] = rnd.next((long long)ceil(1.0 / dcm[i]),
      min((long long) floor(1000000.0 / dcm[i]), 5000ll));
      c[i] = w[i] * dcm[i];
    }

	}
  
  for (int k = 1; k <= 50; k++) {
    int i = rnd.next(1, n), j = rnd.next(1, n);
    swap(w[i], w[j]); swap(c[i], c[j]);
  }
	for (int i = 1; i <= n; i++) 
    cout << q[i] << ' ' << w[i] << ' ' << c[i] << '\n';
	for (auto [x, y] : tree)
	    cout << x + 1 << ' ' << y + 1 << '\n';
}