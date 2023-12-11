#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (auto &p : a) {
        cin >> p.first >> p.second;
        p.first--; p.second--;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int cnt = 0;
    do {
        bool flag = false;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (p[i] > j && p[j] > i)
                    flag = true;
        for (auto q : a)
            if (p[q.first] != q.second)
                flag = false;
        if (flag) cnt++;
    } while (next_permutation(p.begin(), p.end()));
    cout << cnt << '\n';

}
