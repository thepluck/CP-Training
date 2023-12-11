#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N]; vector <int> st;

int main(){
    freopen("bracket.inp", "r", stdin);
    freopen("bracket.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    st.push_back(0);
    int res = 0, cnt = 1;
    for (int i = 1; i <= n; i++){
        if (s[i] == '(')
            a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
        int mid = i;
        while (!st.empty() &&
        a[st.back()] >= a[i]){
            if (a[st.back()] == a[i])
                mid = min(mid, st.back());
            st.pop_back();
        }
        if (res < i - mid){
            res = i - mid; cnt = 1;
        }
        else if (res == i - mid) cnt++;
        st.push_back(mid);
    }
    if (!res) cnt = 1;
    cout << res << ' ' << cnt << '\n';
}