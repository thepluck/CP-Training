#include <bits/stdc++.h>

using namespace std;

struct state {
    int close = 0, open = 0, length = 0;
    
    state() {}
    
    state(char c) {
        if (c == '(') open = 1;
        else close = 1;
    }
    
    state operator += (const state &o) {
        int match = min(open, o.close);
        open += o.open - match;
        close += o.close - match;
        length += o.length + match;
        return *this;
    }
    
    state operator + (const state &o) const {
        return state(*this) += o;
    }
};

const int LG = 20;

state rmq[LG][1 << LG];
char str[1 << LG]; int lg[1 << LG];

int main() {
    memset(str, '(', sizeof str);
    for (int i = 2; i < (1 << LG); i++)
        lg[i] = lg[i / 2] + 1;
    cin >> str; int n = strlen(str);
    int m = 1; while (m < n) m <<= 1;
    for (int k = 0; (1 << k) < m; k++)
        for (int i = 1 << k; i < m; i += 1 << (k + 1)) {
            rmq[k][i - 1] = state(str[i - 1]);
            for (int j = i - 2; j >= i - (1 << k); j--)
                rmq[k][j] = state(str[j]) + rmq[k][j + 1];
            rmq[k][i] = state(str[i]);
            for (int j = i + 1; j < i + (1 << k); j++)
                rmq[k][j] = rmq[k][j - 1] + state(str[j]);  
        }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; l--; r--;
        if (l == r) cout << "0\n";
        else {
            int k = lg[l ^ r];
            cout << (rmq[k][l] + rmq[k][r]).length * 2 << '\n';
        }
    }
}