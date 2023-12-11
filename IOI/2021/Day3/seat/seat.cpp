#include <bits/stdc++.h>
#include "seat.h"

using namespace std;

const int MAXN = 200005;

int nxt[MAXN], prv[MAXN], type[MAXN];
multiset <int> buck[MAXN]; int cnt;
long long res = 0;

bool merge(int i) {
    if (i < 0) return false;
    int j = nxt[i];
    if (j == cnt) return false;
    if (buck[i].size() < buck[j].size())
        swap(buck[i], buck[j]);
    buck[i].insert(buck[j].begin(), buck[j].end());
    buck[j].clear();
    nxt[i] = nxt[j];
    prv[nxt[i]] = i;
    return 1;
}

long long query(const vector <int> &B) {
    int x = B.back(), val[2];
    for (int i = 0; i < cnt; i = nxt[i]) {
        buck[i].insert(x);
        if (type[i]) x = *buck[i].rbegin();
        else x = *buck[i].begin();
        buck[i].erase(buck[i].find(x));
    }
    res += x;
    for (int i = 0; i < cnt && nxt[i] < cnt; ) {
        int j = nxt[i];
        if (type[i]) {
            val[1] = *buck[i].rbegin();
            val[0] = *buck[j].begin();
        } else {
            val[0] = *buck[i].begin();
            val[1] = *buck[j].rbegin();
        }
        if (val[0] >= val[1]) {
            swap(type[i], type[j]);
            swap(buck[i], buck[j]);
            merge(j);
            if (merge(prv[i])) i = prv[i];
            else i = j;
        } else i = j;
    }
    return res;
}

void prepare(int N, vector <int> A, string C, int Q) {
    for (int i = 0; i < N; ) {
        int j = i;
        while (j < N && C[i] == C[j])
            buck[cnt].insert(A[j++]);
        type[cnt++] = C[i] == 'S';
        i = j;
    }
    for (int i = 0; i < cnt; i++) {
        prv[i] = i - 1;
        nxt[i] = i + 1;
    }
    prv[cnt] = cnt - 1;
}