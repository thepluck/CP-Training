#include "MXORLIB.h"

int main(){
    int N = get_n();
    int A[17], ext = -1, dif = 0;
    for (int k = 0; k < 17; k++) {
        vector <int> L, R;
        for (int i = 1; i <= N; i++)
            if (i >> k & 1)
                R.push_back(i);
            else L.push_back(i);
        if (L.size() && R.size())
            A[k] = max_xor(L, R);
        else A[k] = -1;
        ext = max(ext, A[k]);
    }
    for (int k = 0; k < 17; k++)
        if (A[k] == ext)
            dif += 1 << k;
    vector <int> L, R;
    for (int i = 1; i <= N; i++)
        if ((i ^ dif) > 0 && (i ^ dif) < i) {
            L.push_back(i ^ dif);
            R.push_back(i);
        }
    int lo = 0, hi = L.size() - 1;
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        vector <int> X, Y;
        for (int i = 0; i <= mi; i++) {
            X.push_back(L[i]);
            Y.push_back(R[i]);
        }
        if (max_xor(X, Y) == ext)
            hi = mi;
        else lo = mi + 1;
    }
    answer(L[hi], R[hi]);
}
