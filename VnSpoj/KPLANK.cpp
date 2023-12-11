#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N], l[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; stack <int> st;
    st.push(0); int ans = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i]; 
        while (st.top() && a[st.top()] >= a[i]) st.pop();
        l[i] = st.top() + 1; st.push(i);
        //cout << l[i] << ' ';
    }
    stack <int> ().swap(st); st.push(n + 1);
    for (int i = n; i >= 1; i--){
        while (st.top() <= n && a[st.top()] >= a[i]) st.pop();
        if (st.top() - l[i] >= a[i]) ans = max(ans, a[i]);
        st.push(i);
    }
    cout << ans << '\n';
}