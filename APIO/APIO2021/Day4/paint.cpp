
#include "paint.h"
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXM = 50005;
 
int minimumInstructions
(int N, int M, int K,
vector <int> C, vector <int> A,
vector <vector <int>> B) {
    vector <int> cnt(M);
    vector <vector <int>> D(K);
    for (int i = 0; i < M; i++)
        for (int j : B[i])
            D[j].push_back(i);
    int cur = 0;
    for (int i = 0; i + 1 < M; i++)
        for (int j : D[C[i]])
            cnt[(j - i % M + M) % M]++;
    vector <int> P;
    for (int i = M - 1; i < N; i++) {
        for (int j : D[C[i]])
            if (++cnt[(j - i % M + M) % M] == M)
                cur++;
        if (cur) P.push_back(i - M + 1);
        for (int j : D[C[i - M + 1]])
            if (cnt[(j - (i - M + 1) % M + M) % M]-- == M)
                cur--;
    }
    cur = 0; int res = 0;
    for (int i = 0; i < P.size(); ) {
        int nxt = -1;
        while (i < P.size() && P[i] <= cur)
            nxt = P[i++] + M;
        if (nxt < 0) break;
        res++; cur = nxt;
    }
    return cur < N ? -1 : res;
}
