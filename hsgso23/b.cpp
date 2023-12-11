/// fuck your mother
/*
                                      /;    ;\
                                  __  \\____//
                                 /{_\_/   `'\____
                                 \___   (o)  (o  }
      _____________________________/          :--'
  ,-,'`@@@@@@@@       @@@@@@         \_    `__\
 ;:(  @@@@@@@@@        @@@             \___(o'o)
 :: )  @@@@          @@@@@@        ,'@@(  `===='
 :: : @@@@@:          @@@@         `@@@:
 :: \  @@@@@:       @@@@@@@)    (  '@@@'
 ;; /\      /`,    @@@@@@@@@\   :@@@@@)
 ::/  )    {_----------------:  :~`,~~;
;;'`; :   )                  :  / `; ;
;;;; : :   ;                  :  ;  ; :
`'`' / :  :                   :  :  : :
   )_ \__;      ";"          :_ ;  \_\       `,','
   :__\  \    * `,'*         \  \  :  \   *  8`;'*
       `^'     \ :/           `^'  `-^-'   \v/ :
*/
#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 5;
const int LOG = 17;

int dep[N], par[N][LOG], ans[N][LOG];
char s[N];

void solve() {
  int n, q, p;
  cin >> n >> q >> p >> (s + 1);
  ans[0][0] = 1;
  for (int i = 1; i <= n; i++)
    ans[i][0] = (long long)ans[i - 1][0] * (s[i] - 'a' + 1) % p;
  for (int i = 2, j = 0; i <= n; i++) {
    while (j > 0 && s[i] != s[j + 1]) j = par[j][0];
    if (s[i] == s[j + 1]) j++; par[i][0] = j;
  }
  for (int i = 1; i <= n; i++) {
    dep[i] = dep[par[i][0]] + 1;
    for (int k = 1; k < LOG; k++) {
      par[i][k] = par[par[i][k - 1]][k - 1];
      ans[i][k] = max(ans[i][k - 1], ans[par[i][k - 1]][k - 1]);
    }
  }
  while (q--) {
    int u, v, res = 1; cin >> u >> v;
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LOG - 1; k >= 0; k--)
      if (dep[par[u][k]] >= dep[v]) {
        res = max(res, ans[u][k]);
        u = par[u][k];
      }
    if (u == v) {
      cout << res << '\n'; continue;
    }
    for (int k = LOG - 1; k >= 0; k--)
      if (par[u][k] != par[v][k]) {
        res = max({res, ans[u][k], ans[v][k]});
        u = par[u][k]; v = par[v][k];
      }
    cout << max({res, ans[u][0], ans[v][0]}) << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int sub, t; cin >> sub >> t;
  while (t--) solve();
}