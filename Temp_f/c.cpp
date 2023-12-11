#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int col[N], vis[N], tim;
int t, n, q; 

int count1(int l, int r) {
    if (l == r) return 1;
    cout << "? " << l << ' ' << r << endl;
    cin >> l; return l;
}

int count2(int l, int r) {
    tim++;
    for (int i = l; i <= r; i++)
        vis[col[i]] = tim;
    return count(vis + 1, vis + n + 1, tim);
}

void answer() {
    cout << '!';
    for (int i = 1; i <= n; i++)
        cout << ' ' << col[i];
    cout << endl;
}

int main() {
    cin >> t >> n >> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        if (3 <= t && t <= 4)
            l = max(l, i - t + 1);
        while (l < r) {
            int m = (l + r) / 2;
            if (count1(m, i) == count2(m, i - 1) + 1)
                r = m;
            else l = m + 1;
        }
        if (r > 1) col[i] = col[r - 1];
        else col[i] = ++cnt;
    }   
    answer();
}