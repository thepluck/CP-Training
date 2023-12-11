#include <bits/stdc++.h>

using namespace std;

long long area(int i, int j, int k) {
    cout << 1 << ' ' << i << ' ' << j << ' ' << k << endl;
    long long area; cin >> area; return area;
}

int sign(int i, int j, int k) {
    cout << 2 << ' ' << i << ' ' << j << ' ' << k << endl;
    int sign; cin >> sign; return sign;
}

void answer(const vector <int> &poly) {
    cout << 0;
    for (int i : poly) cout << ' ' << i;
    cout << endl;
}

const int MAXN = 1005;

long long A[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector <int> half[2];
    for (int i = 3; i <= N; i++) {
        half[sign(i, 1, 2) > 0].push_back(i);
        A[i] = area(i, 1, 2);
    }
    vector <int> quarter[4];
    sort(half[0].begin(), half[0].end(),
    [&](int i, int j) {
        return A[i] < A[j];
    });
    sort(half[1].begin(), half[1].end(),
    [&](int i, int j) {
        return A[i] < A[j];
    });
    if (half[0].size()) {
        int j = half[0].back();
        for (int i : half[0]) if (i != j) {
            if (sign(i, 1, j) < 0)
                quarter[0].push_back(i);
            else quarter[1].push_back(i);
        }
        quarter[0].push_back(j);
    }
    reverse(quarter[1].begin(), quarter[1].end());
    if (half[1].size()) {
        int j = half[1].back();
        for (int i : half[1]) if (i != j) {
            if (sign(i, 2, j) < 0)
                quarter[2].push_back(i);
            else quarter[3].push_back(i);
        }
        quarter[2].push_back(j);
    }
    reverse(quarter[3].begin(), quarter[3].end());
    quarter[1].push_back(2);
    quarter[3].push_back(1);
    vector <int> poly;
    for (int k = 0; k < 4; k++)
        for (int i : quarter[k])
            poly.push_back(i);
    rotate(poly.begin(), find(poly.begin(),
    poly.end(), 1), poly.end());
    answer(poly);
}