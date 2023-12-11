#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int w[3], h[3], wn[3], hn[3];
    for (int i = 0; i < 3; i++)
        cin >> w[i] >> h[i];
    long long res = LLONG_MAX;
    vector <int> perm{0, 1, 2};
    do {
        for (int i = 0; i < 3; i++){
            wn[i] = w[perm[i]];
            hn[i] = h[perm[i]];
        }
        for (int x = 0; x < 2; x++){
            for (int y = 0; y < 2; y++){
                for (int z = 0; z < 2; z++){
                    long long tmp = (wn[0] + wn[1] + wn[2]) * max({hn[0], hn[1], hn[2]});
                    res = min(res, tmp);
                    tmp = (max(wn[0], wn[1]) + wn[2]) * max(hn[0] + hn[1], hn[2]);
                    res = min(res, tmp);
                    swap(wn[2], hn[2]);
                }
                swap(wn[1], hn[1]);
            }
            swap(wn[0], hn[0]);
        }
    }
    while (next_permutation(perm.begin(), perm.end()));
    cout << res << '\n';
}