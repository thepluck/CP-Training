#define emp emplace_back
#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > a(2010);
bool avail[2010], instack[2010];

int dfs(int u, int par){
    avail[u] = 0; instack[u] = 1;
    int res = 0;
    for (int v : a[u])
        if (v != par){
            if (instack[v]) res++;
            if (avail[v]) res += dfs(v, u);
        }
    instack[u] = 0;
    return res;
}

int main(){
	int n, m; cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		a[u].emp(v); a[v].emp(u);
	}
	memset(avail, 1, sizeof avail);
	memset(instack, 0, sizeof instack);
	int res = 0;
	for (int u = 1; u <= n; u++) if (avail[u]) res += dfs(u, 0);
	cout << res;
}
