#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int N; bool vis[MAXN], used[MAXN];
vector <int> ans;

int ask(const vector <int> &vec) {
	for (int x : vec) cout << x << ' ';
	cout << endl;
	int x; cin >> x;
	if (x == N) exit(0);
	return x;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	vector <int> vec;
	for (int i = 1; i <= N; i++) {
		int cnt = 0, pre;
		for (int x = 1; x <= N; x++) {
			if (vis[x]) continue;
			if (cnt++ == N - i) {
				pre = x; break;
			}
			vec.clear();
			for (int y : ans)
				vec.push_back(y);
			vec.push_back(x);
			for (int y = 1; y <= N; y++)
				if (y != x && !vis[y])
					vec.push_back(y);
			int a1 = ask(vec);
			vec.clear();
			for (int y : ans)
				vec.push_back(y);
			for (int y = 1; y <= N; y++)
				if (y != x && !vis[y])
					vec.push_back(y);
			vec.push_back(x);
			int a2 = ask(vec);
			if (a1 > a2) {
				pre = x; break;
			}
		}
		vector <int> tmp(1, pre);
		memset(used, 0, sizeof used);
		used[pre] = true;
		vec.clear();
		for (int y : ans)
			vec.push_back(y);
		vec.push_back(pre);
		for (int y = 1; y <= N; y++)
			if (!used[y] && !vis[y])
				vec.push_back(y);
		int lcs = ask(vec);
		for (int x = pre + 1; x <= N; x++) {
			if (vis[x]) continue;
			vec.clear();
			for (int y : ans)
				vec.push_back(y);
			vec.push_back(x);
			for (int i = tmp.size() - 1; i >= 0; i--)
				vec.push_back(tmp[i]);
			for (int y = 1; y <= N; y++)
				if (y != x && !vis[y] && !used[y])
					vec.push_back(y);
			int a = ask(vec);
			if (a > lcs) {
				tmp.push_back(x); used[x] = true;
				lcs = a;
			}
		}
		vis[tmp.back()] = true;
		ans.push_back(tmp.back());
	}
}
