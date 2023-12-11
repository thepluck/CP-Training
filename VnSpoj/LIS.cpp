#include <iostream>
using namespace std;
 
const int MAXN = 1e5 + 5;
 
int n, a[MAXN], h[MAXN];
 
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i]; 
    int L = 1; h[1] = 1;
    for(int i = 2; i <= n; i++) {
        int lo = 1, hi = L;
        while(lo <= hi) {
            int mi = (lo + hi) / 2;
            if (a[h[mi]] < a[i]) lo = mi + 1;
            else hi = mi - 1;
        }
        h[lo] = i; L = max(L, lo);
    }
    cout << L << '\n';
}
