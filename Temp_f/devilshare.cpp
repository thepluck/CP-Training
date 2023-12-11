//https://oj.uz/problem/view/RMI19_devil
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k; cin >> k;
    vector <int> num(10);
    for (int i = 1; i <= 9; i++)
        cin >> num[i];
    string b; int cur = 0;
    for (int i = 9; i; i--)
        while (num[i] && cur < k - 1){
            cur++; num[i]--;
            b.push_back(i + '0');
        }
    reverse(b.begin(), b.end());
    vector <string> a;
    deque <string> dq;
    for (int i = 9; i; i--)
        if (num[i]){
            a.resize(num[i],
            string(1, i + '0'));
            num[i] = 0; break;
        }
    for (int i = 1; i < 10; i++)
        while (num[i]){
            num[i]--;
            dq.push_back(
            string(1, i + '0'));
        }
    int pos = a.size() - 1;
    while (!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        a[pos] += cur;
        if ((dq.empty() ||
        dq.front() != cur) && pos)
            while (a.size() > pos){
                dq.push_back(a.back());
                a.pop_back();
            }
        pos--;
        if (pos < 0) pos += a.size();
    }
    for (auto str : a) cout << str;
    cout << b << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}