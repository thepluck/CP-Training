#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 5;
int l[N], r[N]; ll a[N];

int main(){
    freopen("weight.inp", "r", stdin);
    freopen("weight.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; ll res = 0; cin >> n;
    vector <int> st;
    st.clear(); st.push_back(0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        while (st.back() &&
        a[st.back()] >= a[i]) st.pop_back();
        l[i] = st.back(); st.push_back(i);
    }
    st.clear(); st.push_back(n + 1);
    for (int i = n; i > 0; i--){
        while (st.back() <= n &&
        a[st.back()] > a[i]) st.pop_back();
        r[i] = st.back(); st.push_back(i);
        res -= a[i] * (r[i] - i) * (i - l[i]);
    }
    st.clear(); st.push_back(0);
    for (int i = 1; i <= n; i++){
        while (st.back() &&
        a[st.back()] <= a[i]) st.pop_back();
        l[i] = st.back(); st.push_back(i);
    }
    st.clear(); st.push_back(n + 1);
    for (int i = n; i > 0; i--){
        while (st.back() <= n &&
        a[st.back()] < a[i]) st.pop_back();
        r[i] = st.back(); st.push_back(i);
        res += a[i] * (r[i] - i) * (i - l[i]);
    }
    cout << res << '\n';
}
