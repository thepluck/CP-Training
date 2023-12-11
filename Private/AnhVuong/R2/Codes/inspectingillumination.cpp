/// https://open.kattis.com/problems/inspectingillumination

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

struct segment {
    int from, to;
    vector <int> srcs;
};

vector <int> ask(const vector <int> &swis) {
    cout << "ASK " << swis.size();
    for (int x : swis) cout << ' ' << x;
    cout << endl;
    vector <int> srcs(swis.size());
    for (int &x : srcs) cin >> x;
    return srcs;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    bitset <N> mark;
    int n; cin >> n;
    vector <segment> segs;
    segs.push_back({1, n, {}});
    for (int i = 1; i <= n; i++)
        segs.back().srcs.push_back(i);
    while (true) {
        vector <int> swis;
        for (auto seg : segs) {
            if (seg.from == seg.to) continue;
            int pivot = (seg.from + seg.to) / 2;
            for (int x = seg.from; x <= pivot; x++)
                swis.push_back(x);
        }
        if (swis.empty()) break;
        vector <int> srcs = ask(swis);
        for (int x : srcs) mark[x] = true;
        vector <segment> newSegs;
        for (auto seg : segs) {
            if (seg.from == seg.to) {
                newSegs.push_back(seg); continue;
            }
            int pivot = (seg.from + seg.to) / 2;
            vector <int> lef, rig;
            for (int x : seg.srcs)
                if (mark[x]) lef.push_back(x);
                else rig.push_back(x);
            newSegs.push_back({seg.from, pivot, lef});
            newSegs.push_back({pivot + 1, seg.to, rig});
        }
        segs = newSegs;
        for (int x : srcs) mark[x] = false;
    }
    vector <int> ans(n + 1);
    for (auto seg : segs)
        ans[seg.srcs.back()] = seg.from;
    cout << "ANSWER";
    for (int i = 1; i <= n; i++)
        cout << ' ' << ans[i];
    cout << endl;
}