#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int N = 1e5 + 4;
int n;
ii A[N];
string ans[N];

string Add(string a, string b) {
    while ((int) a.length() < (int) b.length()) a += '0';
    while ((int) b.length() < (int) a.length()) b += '0';
   
    int save = 0; string ans = "";
    for (int i = (int) a.length()-1; i >= 0; --i) {
        int k = a[i]-'0' + b[i]-'0' + save;
        save = k / 10;
        char c = (char) ('0' + (k % 10));
        ans = c + ans;
    }
    return ans;
}

string Sub(string a, string b) {
    while ((int) a.length() < (int) b.length()) a += '0';
    while ((int) b.length() < (int) a.length()) b += '0';
    
    int save = 0; string ans = "";
    for (int i = (int) a.length()-1; i >= 0; --i) {
        int k = a[i] - b[i] - save; save = 0;
        if (k < 0) { k += 10; save = 1; }
        ans = (char) ('0' + k % 10) + ans;
    }
    return ans;
}

void sol() {
    sort(A+1, A+n+1);
    if (A[n-1].first != A[n].first) { cout << "NO"; exit(0); }

    string s = "0", t = "1";
    for (int i = 1; i < n; ++i) {
        while ((int) t.length() <= A[i].first) t = '0' + t;
        ans[A[i].second] = t;
        s = Add(s, t);
        if (s[0] == '1') { cout << "NO"; exit(0); }
    }
 
    cout << "YES\n";
 
    string tmp = "1", p = Sub(tmp, s);
    if (p[p.length()-1] == '0') {
        p = Sub(p, t);
        ans[A[n-1].second] = Add(ans[A[n-1].second], t);
    }

    ans[A[n].second] = p;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i][0] << ".";
        for (int j = 1; j < (int) ans[i].size(); ++j) cout << ans[i][j];
        cout << '\n';
    }
}

main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("answer.txt", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i].first; 
        A[i].second = i;
    }

    sol();

    return 0;
}