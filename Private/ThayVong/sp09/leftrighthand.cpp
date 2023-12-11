#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair <int, int>;
const int N = 2e5 + 5;
ii hand[N];

int main(){
    freopen("leftrighthand.inp", "r", stdin);
    freopen("leftrighthand.out", "w", stdout);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> hand[i].first >> hand[i].second;
    sort(hand + 1, hand + n + 1, [](const ii &a, const ii &b){
        return a.first - a.second > b.first - b.second;
    });
    ll total = 0;
    for (int i = 1; i <= k; i++)
        total += hand[i].first;
    for (int i = k + 1; i <= n; i++)
        total += hand[i].second;
    cout << total << '\n';
}