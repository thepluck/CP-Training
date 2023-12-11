#include <bits/stdc++.h>

using namespace std;

bool is_subsequence(const vector <int> &a,
const vector <int> &b) {
    int i = 0;
    for (int j = 0; j < b.size(); j++)
        if (i < a.size() && a[i] == b[j]) i++;
    return i == a.size();
}

int main(int argc, char *argv[]) {
    ifstream input(argv[1]);
    ifstream answer(argv[2]);
    ifstream output(argv[3]);
    int m, n; input >> m >> n;
    vector <int> a(m);
    for (int &x : a) input >> x;
    vector <int> b(n);
    for (int &x : b) input >> x;
    int p, q; answer >> p;
    output >> q;
    vector <int> c(q);
    for (int &x : c) output >> x;
    if (p != q) {
        cout << "Wrong length\n";
    }
    if (!is_subsequence(c, a)
    || !is_subsequence(c, b)) {
        cout << "Wrong sequence\n";
    }
    return 0;
}
