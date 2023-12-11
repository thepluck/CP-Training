#include <bits/stdc++.h>
using namespace std;

struct manacher{
    vector <int> f;
    
    void init(const string &s) {
        f.assign(2 * s.size() + 1, 0);
        string t = "#";
        for (char c: s) {
            t += c; t += '#';
        }
        int n = t.size(), c = 0, r = 0;
        for (int i = 0; i < n; i++) {
            f[i] = i < r ? min(r - i, f[2 * c - i]) : 0;
            while (i > f[i] && i + f[i] + 1 < n && 
            t[i - f[i] - 1] == t[i + f[i] + 1]) f[i]++; 
            if (i + f[i] > r) {
                c = i; r = i + f[i];
            }
        }
    }
 
    bool is_palin(int i, int j) {
        return f[i + j + 1] > j - i;
    }
};

int main() {

}