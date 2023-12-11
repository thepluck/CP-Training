#include <bits/stdc++.h>

using namespace std;


using ld = long double;
using vd = vector<ld>;
using vi = vector<int>;

const double eps = 1e-12;

void solve(vector<vd>& A, vd& b, vd& x) {
	int n = A.size(), rank = 0, br, bc;
	vi col(n); iota(col.begin(), col.end(), 0);
	for (int i = 0; i < n; i++) {
		double v, bv = 0;
		for (int r = i; r < n; r++)
		    for (int c = i; c < n; c++)
    			if ((v = abs(A[r][c])) > bv) {
    				br = r; bc = c; bv = v;
    			}
    	if (bv <= eps) break;
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		for (int j = 0; j < n; j++)
		    swap(A[j][i], A[j][bc]);
		bv = 1 / A[i][i];
		for (int j = i + 1; j < n; j++) {
			ld fac = A[j][i] * bv;
			b[j] -= fac * b[i];
			for (int k = i + 1; k < n; k++)
			    A[j][k] -= fac * A[i][k];
		}
		rank++;
	}
	x.assign(n, 0);
	for (int i = rank; i--;) {
		b[i] /= A[i][i];
		x[col[i]] = b[i];
		for (int j = 0; j < i; j++)
	        b[j] -= A[j][i] * b[i];
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    cout << setprecision(9) << fixed;
    while (q--) {
        string s; cin >> s;
        int n = s.size();
        vector<int> kmp(n);
        vector<vd> A(n, vd(n)); vd b(n), x(n);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && s[i] != s[j])
                j = kmp[j - 1];
            if (s[i] == s[j]) j++; kmp[i] = j;
        }
        for (int i = 0; i < n; i++) {
            A[i][i] = 2; b[i] = 2;
            if (i + 1 < n) A[i][i + 1] = -1;
            int j = i;
            while (j > 0 && s[i] == s[j])
                j = kmp[j - 1];
            if (s[i] != s[j]) j++; A[i][j]--;
        }
        solve(A, b, x); cout << x[0] << '\n';
    }
}