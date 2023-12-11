#include <bits/stdc++.h>

using namespace std;

using ll = long long;

pair <char, ll> block[1005]; ll len[1005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; ll k; int n = 0, q;
    cin >> s >> k >> q;
    for (int i = 0; i < s.size(); ) {
        ll cnt = 0; int j = i + 1;
        while (j < s.size() && isdigit(s[j]))
            cnt = cnt * 10 + (s[j++] - '0');
        block[++n] = {s[i], cnt}; i = j;
        len[n] = len[n - 1] + cnt;
    }
    while (q--) {
        ll l, r, deg = 0; cin >> l >> r;
        ll cntl, cntr, rem; char lef;
        int lo = 0, hi = n, idl, idr;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (l > len[mi])
                idl = lo = mi + 1;
            else hi = mi - 1;
        }
        lo = 0, hi = n;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (r <= len[mi]) {
                idr = mi; hi = mi - 1;
            }
            else lo = mi + 1;
        }
        if (idl == idr) {
            cout << "1\n"; continue;
        }
        cntl = len[idl] - l + 1;
        cntr = r - len[idr - 1];
        rem = cntl - cntr;
        if (block[idl].first != block[idr].first) {
            if (cntl < cntr)
                lef = block[idr].first;
            else if (cntl > cntr)
                lef = block[idl].first;
            deg += min(cntl, cntr); 
        }
        idl++; idr--;
        while (idl <= idr) {
            if (rem > 0) {
                if (block[idr].first != lef)
                    deg += min(rem, block[idr].second);
                rem -= block[idr].second;
                if (rem < 0) lef = block[idr].first;
                idr--;
            }
            else if (rem < 0) {
                if (block[idl].first != lef)
                    deg += min(-rem, block[idl].second);
                rem += block[idl].second;
                if (rem > 0) lef = block[idl].first;
                idl++;
            }
            else {
                rem += block[idl].second;
                lef = block[idl].first; idl++;
            }
        }
        cout << (deg <= k) << '\n';
    }
}