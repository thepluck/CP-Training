#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("alltest.txt", "r", stdin);
    string s, t; int test = 0;
    while (getline(cin, s)) {
        s.erase(0, s.find('{'));
        s.erase(s.find('}') + 1);
        t.clear(); int m = 1;
        for (char c : s) {
            if (c == ' ') {
                m++; t.push_back(c);
            }
            if (isdigit(c)) t.push_back(c);
        }
        int n = 0;
        while (n * (n - 1) / 2 < m) n++;
        if (n * (n - 1) / 2 == m) {
            freopen((to_string(++test) + ".in").data(), "w", stdout);
            cout << n << '\n' << t << '\n';
        }
        getline(cin, s); getline(cin, s);
    }
}