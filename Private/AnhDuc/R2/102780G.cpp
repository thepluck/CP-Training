#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct state {
    int code; short dis;

    state(int code, short dis): code(code), dis(dis) {}

    bool operator < (const state &o) const {
        return dis > o.dis;
    }
};

short sum[4], trc[5200000];
short dis[5200000], n, k;
priority_queue <state> pq;
vector <short> oper[2005];

int decode(int code, short rem[]) {
    int mod = code % 22;
    for (int i = 0; i < n; i++) {
        code /= 22; rem[i] = code % 22;
    }
    return mod;
}

short rem[4], tmp[4], prt[4];

int encode(int mod) {
    int code = mod, pw = 1;
    for (short i = 0; i < n; i++) {
        pw *= 22; code += pw * rem[i];
    }
    return code;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (short i = 0; i < n; i++) cin >> sum[i];
    cin >> k;
    for (short j = 0; j < n; j++) {
        memset(dis, 0x3f, sizeof dis);
        memset(trc, -1, sizeof trc);
        pq.emplace(0, dis[0] = 0);
        while (pq.size()) {
            auto cur = pq.top(); pq.pop();
            if (cur.dis > dis[cur.code]) continue;
            decode(cur.code, rem);
            if (rem[j] == 0 && cur.dis <= k &&
            cur.dis % sum[j] == k % sum[j]) {
                cout << "YES\n";
                int code = cur.code;
                int mod = decode(code, rem);
                int iter = 1;
                while (iter--) {
                    if (trc[code] == -1) {
                        short mask = 0; mod--;
                        if (mod < 0) mod += sum[j];
                        for (short i = 0; i < n; i++)
                            if (rem[i] == 21) mask += 1 << i;
                        for (short smask = mask; ; smask = (smask - 1) & mask) {
                            for (short i = 0; i < n; i++)
                                if (rem[i] == 21) {
                                    if (smask >> i & 1) tmp[i] = 21;
                                    else tmp[i] = 0;
                                }
                                else tmp[i] = rem[i] + 1;
                            
                            int preCode = encode(mod);
                            cerr << preCode << ' ' << dis[preCode] << '\n';
                            if (dis[preCode] == dis[code] + 1) {
                                code = preCode; swap(tmp, rem); break;
                            }
                            if (smask == 0) break;
                        }
                    }
                    else {
                        short mask = 0;
                        for (short i = 0; i < n; i++)
                            if (rem[i] == 20) mask += 1 << i;
                        for (short smask = mask; ; smask = (smask - 1) & mask) {
                            bool flag = false;
                            for (short x = 0; x < (1 << n); x++) {
                                bool have = false;
                                for (short i = 0; i < n; i++)
                                    if (x >> i & 1) {
                                        if (rem[i] == 20) {
                                            if (smask >> i & 1) tmp[i] = 0;
                                            else tmp[i] = 21;
                                        }
                                        else tmp[i] = sum[i] - rem[i];
                                    }
                                    else tmp[i] = rem[i];
                                for (short i = 0; i < n; i++)
                                    if (tmp[i] == 0) have = true;
                                if (!have) continue;
                                int preCode = encode(mod);
                                if (dis[preCode] == dis[code]) {
                                    // for (short i = 0; i < n; i++)
                                    //     if (x >> i & 1)
                                    //         oper[dis[preCode]].push_back(i);
                                    code = preCode; swap(tmp, rem);
                                    flag = true; break;
                                }
                            }
                            if (smask == 0 || flag) break;
                        }
                    }
                }
                while (cur.dis < k) {
                    oper[cur.dis].push_back(j);
                    cur.dis += sum[j];
                }
                short res = 0;
                for (short i = 0; i < k; i++) {
                    memset(prt, 0, sizeof prt);
                    for (short op : oper[i]) prt[op] ^= 1;
                    oper[i].clear();
                    for (short x = 0; x < 4; x++)
                        if (prt[x]) oper[i].push_back(x + 1);
                    if (oper[i].size()) res++;
                }
                cout << res + 1 << '\n';
                for (short i = 0; i < k; i++)
                    if (oper[i].size()) {
                        cout << i << ' ' << oper[i].size();
                        for (int op : oper[i]) cout << ' ' << op;
                        cout << '\n';
                    }
                cout << k << " 0";
                return 0;
            }
            auto nxt = cur; nxt.dis++;
            bool flag = false;
            for (int i = 0; i < n; i++)
                if (rem[i] == 0) {
                    rem[i] = 21; flag = true;
                }
                else if (rem[i] != 21) rem[i]--;
            nxt.code = encode(nxt.dis % sum[j]);
            if (cmin(dis[nxt.code], nxt.dis)) {
                pq.emplace(nxt.code, dis[nxt.code]);
                trc[nxt.code] = -1;
            }
            if (!flag) continue;
            for (short x = 0; x < (1 << n); x++) {
                nxt = cur; decode(nxt.code, rem);
                for (short i = 0; i < n; i++)
                    if (x >> i & 1) {
                        if (rem[i] == 21)
                            rem[i] = sum[i];
                        else rem[i] = sum[i] - rem[i];
                    }
                nxt.code = encode(nxt.dis % sum[j]);
                if (cmin(dis[nxt.code], nxt.dis)) {
                    pq.emplace(nxt.code, dis[nxt.code]);
                    trc[nxt.code] = x;
                }
            }
        }
    }
    cout << "-1\n";
}