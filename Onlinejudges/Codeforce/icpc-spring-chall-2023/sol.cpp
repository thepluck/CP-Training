#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 15;
const int MAX_Q = 1000005;

int N, Q, M;
int L[MAX_N], D[MAX_N];
int Qmin[MAX_N], Qbase[MAX_N], Qmax[MAX_N];

int main() {
  cin >> N >> Q >> M;
  for (int i = 1; i <= N; i++)
    cin >> L[i];
  for (int i = 1; i <= N; i++)
    cin >> D[i];
  for (int i = 1; i <= N; i++)
    cin >> Qmin[i] >> Qbase[i] >> Qmax[i];
  for (int tc = 1; tc <= M; tc++) {
    int u, p; cin >> u >> p;
  }
}