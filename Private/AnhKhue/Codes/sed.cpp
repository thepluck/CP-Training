#include <bits/stdc++.h>

using namespace std;

unordered_map <string, int> dis;

int main() {
    freopen("sed.in", "r", stdin);
    freopen("sed.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <pair <string, string>> opers(n);
    for (auto &oper : opers)
        cin >> oper.first >> oper.second;
    string start, target, del, rep;
    cin >> start >> target;
    queue <string> que;
    que.push(start); dis[start] = 0;
    while (que.size()) {
        string curstr = que.front(); que.pop();
        if (curstr.size() > 100) continue;
        if (curstr == target) {
            cout << dis[target] << '\n'; return 0;
        }
        for (auto oper : opers) {
            tie(del, rep) = oper;
            string nextstr = curstr;
            for (int i = 0; i < int(nextstr.size()); ) {
                int j = nextstr.find(del, i);
                if (j < 0) break;
                nextstr.replace(j, del.size(), rep);
                i = j + rep.size();
            }
            if (!dis.count(nextstr)) {
                dis[nextstr] = dis[curstr] + 1;
                que.push(nextstr);
            }
        }
    }
    cout << "-1\n";
}
