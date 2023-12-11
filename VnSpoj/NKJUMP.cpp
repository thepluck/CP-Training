#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int path[N], a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n); path[0] = path[1] = 1;
    for (int i = 2; i < n; i++){
        int l = 0, r = i - 1;
        while (l < r){
            if (a[l] + a[r] >= a[i]){
                if (a[l] + a[r] == a[i])
                    path[i] = max({path[i], path[l], path[r]});
                r--;
            }
            else l++;
        }
        path[i]++;
    }
    cout << *max_element(path, path + n) << '\n';
}