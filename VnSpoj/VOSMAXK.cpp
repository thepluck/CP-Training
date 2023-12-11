#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    long long res = 0;
    stack <int> st; st.push(-1);
    vector <int> a(n), l(n), r(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        while (st.size() > 1 && a[st.top()] < a[i]) st.pop();
        l[i] = st.top() + 1; st.push(i);
    }
    stack <int>().swap(st); st.push(n);
    for (int i = n - 1; ~i; i--){
        while (st.size() > 1 && a[st.top()] <= a[i]) st.pop();
        r[i] = st.top() - 1; st.push(i);
    }
    for (int i = 0; i < n; i++)
        if (a[i] == k)
            res += 1ll * (i - l[i] + 1) * (r[i] - i + 1);
    cout << res << '\n';
}