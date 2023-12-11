#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937_64 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution <int> (l, r)(rng);
}

map <ll, string> mp;

ll ask(const string &s) {
    cout << "? " << s << endl;
    ll res; cin >> res; return res;
}

void answer(const string &a, const string &b) {
    assert(a.size() == 20);
    assert(b.size() == 20);
    cout << "! " << a << ' ' << b << endl;
    exit(0);
}

string randStr(int len) {
    string s;
    while (len--) s.push_back('a' + randInt(0, 25));
    return s;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (true) {
        string s = randStr(20);
        ll hashCode = ask(s);
        if (mp.count(hashCode))
            answer(s, mp[hashCode]);
        mp[hashCode] = s;
    }
}