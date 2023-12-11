#include <bits/stdc++.h>
using namespace std;
string s;
int ok;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ahihi.inp","r",stdin); freopen("ahihi.out","w",stdout);

    getline(cin, s);

    if (s == "cai gi") cout << "cai do", ok = 1;

    if (s == "gi") cout << "nay", ok = 1;

    if (s == "bat cu cai gi") cout << "tat ca cac cai da doc", ok = 1;

    if (s == "het") cout << "tat ca", ok = 1;

    if (s == "mot dong") cout << "mot dong", ok = 1;

    if (s == "mot cau") cout << "mot cau", ok = 1;

    if (s == "mot chu") cout << "mot chu", ok = 1;

    if (s == "mot vai thu") cout << "tat ca nhung thu do", ok = 1;

    if (ok == 0)
    cout << "tat ca moi thu da doc";
}
