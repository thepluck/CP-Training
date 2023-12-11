#include <bits/stdc++.h>

using namespace std;

bitset <(1 << 21)> mark;
int out[44640], cnt;

void genCode() {
    for (int mask = 0; mask < (1 << 21); mask++) {
        if (mark[mask]) continue;
        if (cnt == 44640) break;
        bool flag = true;
        for (int i = 0; i < 21; i++)
            if (mark[mask ^ (1 << i)]) {
                flag = false; break;
            }
        if (!flag) continue;
        out[cnt++] = mask;
        mark[mask] = true;
        for (int i = 0; i < 21; i++)
            mark[mask ^ (1 << i)] = true;
    }
}

string toBin(int x, int k) {
    string s;
    for (int i = 0; i < k; i++) {
        s.push_back('0' + (x & 1)); x >>= 1;
    }
    reverse(s.begin(), s.end()); return s;
}

int toDec(string s) {
    int k = s.size(), x = 0;
    for (int i = 0; i < k; i++)
        x = (x << 1) + s[i] - '0';
    return x;
}

string encode(const string rawMessage) {
#define raw rawMessage
    genCode();
    int dd = (raw[0] - '0') * 10 + raw[1] - '0';
    int hh = (raw[3] - '0') * 10 + raw[4] - '0';
    int mm = (raw[6] - '0') * 10 + raw[7] - '0';
    return toBin(out[dd - 1 + hh * 31 + mm * 31 * 24], 21);
}

string decode(const string encryptedMessage) {
    string cry = encryptedMessage; genCode();
    int pos = lower_bound(out, out + cnt, toDec(cry)) - out;
    if (pos != cnt && out[pos] == toDec(cry)) {
        int dd = pos % 31 + 1; pos /= 31;
        int hh = pos % 24; pos /= 24;
        int mm = pos;
        string raw;
        raw.push_back(dd / 10 + '0');
        raw.push_back(dd % 10 + '0');
        raw.push_back(' ');
        raw.push_back(hh / 10 + '0');
        raw.push_back(hh % 10 + '0');
        raw.push_back(':');
        raw.push_back(mm / 10 + '0');
        raw.push_back(mm % 10 + '0');
        return raw;
    }
    for (int i = 0; i < 21; i++) {
        cry[i] ^= 1;
        pos = lower_bound(out, out + cnt, toDec(cry)) - out;
        if (pos != cnt && out[pos] == toDec(cry)) {
            int dd = pos % 31 + 1; pos /= 31;
            int hh = pos % 24; pos /= 24;
            int mm = pos;
            string raw;
            raw.push_back(dd / 10 + '0');
            raw.push_back(dd % 10 + '0');
            raw.push_back(' ');
            raw.push_back(hh / 10 + '0');
            raw.push_back(hh % 10 + '0');
            raw.push_back(':');
            raw.push_back(mm / 10 + '0');
            raw.push_back(mm % 10 + '0');
            return raw;
        }
        cry[i] ^= 1;
    }
}