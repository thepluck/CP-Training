// Problem: E. New Game Plus!
// Contest: Codeforces - Technocup 2021 - Elimination Round 2
// URL: https://codeforces.com/contest/1415/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    priority_queue <long long> pq;
    long long ans = 0, sum;
    for (int i = 0; i <= k; i++)
        pq.push(0);
    for (int x : a) {
        sum = pq.top(); pq.pop();
        ans += sum; sum += x;
        pq.push(sum);
    }
    cout << ans << '\n';
}