#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

const int MAXN = 10005;

int even[MAXN], odd[MAXN];
int neven[MAXN], nodd[MAXN];
int subtask, N;

int compare(int i, int j) {
    cout << "compare " << i << ' ' << j << endl;
    char c; cin >> c;
    return c == '>';
}

void answer() {
    cout << "answer";
    for (int i = 1; i <= N / 2; i++)
        cout << ' ' << even[i];
    for (int i = 1; i <= (N + 1) / 2; i++)
        cout << ' ' << odd[i];
    cout << endl;
}

void solve(int l, int r,
const vector<int> &ide, const vector<int> &ido) {
    if (l > r) return;
    if (r - l < 2) {
        for (int i : ide)
            even[i] = l & 1 ? l + 1 : l;
        for (int i : ido)
            odd[i] = l & 1 ? l : l + 1;
        return;
    }
    int pv = rand(0, ide.size() - 1);
    vector <int> idol, idor;
    vector <int> idel, ider;
    for (int i = 0; i < ido.size(); i++)
        if (compare(ide[pv], ido[i]))
            idol.push_back(ido[i]);
        else idor.push_back(ido[i]);
    int ptrl = 0, ptrr = 0;
    for (int i = 0; i < ide.size(); i++) {
        if (i == pv) continue;
        int tmpl = ptrl, tmpr = ptrr;
        while (true) {
            if (tmpl < idol.size() &&
            !compare(ide[i], idol[tmpl])) {
                idel.push_back(ide[i]);
                ptrl = tmpl; break;
            }
            if (tmpr < idor.size() &&
            compare(ide[i], idor[tmpr])) {
                ider.push_back(ide[i]);
                ptrr = tmpr; break;
            }
            tmpl++; tmpr++;
        }
    }
    even[ide[pv]] = l + idel.size() + idol.size();
    if (idol.size()) {
        odd[idol[ptrl]] = even[ide[pv]] - 1;
        idol.erase(idol.begin() + ptrl);
        solve(l, even[ide[pv]] - 2, idel, idol);
    }
    if (idor.size()) {
        odd[idor[ptrr]] = even[ide[pv]] + 1;
        idor.erase(idor.begin() + ptrr);
        solve(even[ide[pv]] + 2, r, ider, idor);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> subtask >> N;
    vector <int> ide, ido;
    for (int i = 1; i <= N; i++)
        if (i & 1) ido.push_back((i + 1) / 2);
        else ide.push_back(i / 2);
    solve(1, N, ide, ido); answer();
}