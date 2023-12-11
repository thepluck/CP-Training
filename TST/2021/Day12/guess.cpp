#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "april fool";
    long long n; cin >> n;
    cout << s[(n - 1) % 10];
}