#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int l[N], r[N], a[N];

int main(){
    freopen("rect.inp", "r", stdin);
    freopen("rect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> m >> n;
    vector <int> st;
    long long res = 0;
    st.clear();
    st.push_back(0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        while (st.back() &&
        a[st.back()] >= a[i])
            st.pop_back();
        l[i] = st.back() + 1;
        st.push_back(i);
    }
    st.clear();
    st.push_back(n + 1);
    for (int i = n; i > 0; i--){
        while (st.back() <= n &&
        a[st.back()] >= a[i])
            st.pop_back();
        r[i] = st.back() - 1;
        st.push_back(i);
        res = max(res, 1ll *
        (r[i] - l[i] + 1) * a[i]);
    }
    st.clear();
    st.push_back(0);
    for (int i = 1; i <= n; i++){
        a[i] = m - a[i];
        while (st.back() &&
        a[st.back()] >= a[i])
            st.pop_back();
        l[i] = st.back() + 1;
        st.push_back(i);
    }
    st.clear();
    st.push_back(n + 1);
    for (int i = n; i > 0; i--){
        while (st.back() <= n &&
        a[st.back()] >= a[i])
            st.pop_back();
        r[i] = st.back() - 1;
        st.push_back(i);
        res = max(res, 1ll *
        (r[i] - l[i] + 1) * a[i]);
    }
    cout << res << '\n';
}
