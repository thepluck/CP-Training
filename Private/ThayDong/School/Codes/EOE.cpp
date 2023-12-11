#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, p, q, t;
    cin >> s >> p >> q;
    int x = p[0] == 'O', y = q[0] == 'O';
    for (int i = 0; i < s.size(); i++)
        if (i == s.size() - 1 ||
        !(isdigit(s[i]) && isdigit(s[i + 1]))) {
            if (s[i] == 'x')
                t.push_back(x + '0');
            else if (s[i] == 'y')
                t.push_back(y + '0');
            else if (isdigit(s[i]))
                t.push_back((s[i] - '0') % 2 + '0');
            else t.push_back(s[i]);
        }
    int cur = 0;
    for (int i = 0; i < t.size(); i++)
        if (isdigit(t[i])) {
            int tmp = t[i] - '0', j = i + 1;
            while (j < t.size() && t[j] == '*') {
                tmp *= (t[j + 1] - '0'); j += 2;
            }
            cur += tmp; i = j - 1;
        }
    cout << (cur & 1 ? "Odd\n" : "Even\n");
}