#include <bits/stdc++.h>
#include "floppy.h"

using namespace std;

void read_array(int subtask_id, const vector <int> &V) {
    string bits; stack <int> s;
    int N = V.size();
    for (int i = 0; i < N; i++) {
        while (s.size() && V[i] > V[s.top()]) {
            bits.push_back('1'); s.pop();
        }
        bits.push_back('0'); s.push(i);
    }
    save_to_floppy(bits);
}

struct segment_tree {
    vector <int> A; int N;

    segment_tree(int N, const vector <int> &V): N(N), A(N * 4) {
        build(1, 0, N - 1, V);
    }

    void build(int i, int l, int r, const vector <int> &V) {
        if (l == r) A[i] = V[l];
        else {
            int m = (l + r) / 2;
            build(i * 2, l, m, V);
            build(i * 2 + 1, m + 1, r, V);
            A[i] = min(A[i * 2], A[i * 2 + 1]);
        }
    }

    int find_pos(int i, int l, int r, int lo, int hi) {
        if (l > hi || r < lo || A[i] > lo) return -1;
        if (l == r) return l;
        int m = (l + r) / 2;
        int pos = find_pos(i * 2 + 1, m + 1, r, lo, hi);
        if (pos < 0) pos = find_pos(i * 2, l, m, lo, hi);
        return pos;
    }

    int find_pos(int lo, int hi) {
        return find_pos(1, 0, N - 1, lo, hi);
    }
};

vector <int> solve_queries
(int subtask_id, int N, const string &bits,
const vector<int> &a, const vector<int> &b) {
    vector <int> L(N);
    stack <int> s; s.push(-1);
    for (int i = 0, j = 0; i < N; i++, j++) {
        while (bits[j] == '1') {
            s.pop(); j++;
        }
        L[i] = s.top() + 1; s.push(i);
    }
    segment_tree ST(N, L);
    vector <int> pos;
    for (int i = 0; i < int(a.size()); i++)
        pos.push_back(ST.find_pos(a[i], b[i]));
    return pos;
}
