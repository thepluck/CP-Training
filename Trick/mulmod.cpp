#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mmul(ll x, ll y, ll m) {
    ll q = double(x) * y / double(m);
    ll res = x * y - q * m;
    res = (res % m + m) % m;
    return res;
}

int main() {
	
}