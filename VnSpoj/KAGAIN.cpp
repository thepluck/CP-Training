#define pub push_back
#define pob pop_back
#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e4 + 10;
int a[maxn], l[maxn], r[maxn];
vector <int> st; int n, t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        st.clear(); st.pub(0);
        for (int i = 1; i <= n; i++){
            while (st.back() != 0 && a[st.back()] >= a[i]) st.pob();
            l[i] = st.back() + 1; st.pub(i);
        }
        st.clear(); st.pub(n + 1);
        for (int i = n; i > 0; i--){
            while (st.back() != n + 1 && a[st.back()] >= a[i]) st.pob();
            r[i] = st.back() - 1; st.pub(i);
        }
        long long res = 0; int id = 0;
        for (int i = 1; i <= n; i++)
            if (1ll * (r[i] - l[i] + 1) * a[i] > res){
                res = (r[i] - l[i] + 1) * a[i]; id = i;
            }
        cout << res << ' ' << l[id] << ' ' << r[id] << '\n';
    }
}
