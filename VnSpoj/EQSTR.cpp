#include <bits/stdc++.h>
using namespace std;

int cost[26][26], pos[26][26];
void pre_calc(){
    memset(cost, 0x3f, sizeof(int) * 26 * 26);
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 26; k++){
                if (cost[i][j] > min(abs(i - k), 26 - abs(i - k)) + min(abs(j - k), 26 - abs(j - k))){
                    pos[i][j] = k; cost[i][j] = min(abs(i - k), 26 - abs(i - k)) + min(abs(j - k), 26 - abs(j - k));
                }
            }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pre_calc(); string cmd, s, t;
    while (cin >> cmd){
        if (cmd == "[END]") return 0;
        cin >> s >> t;
        for (int i = 0; s[i]; i++)
            cout << char('a' + pos[s[i] - 'a'][t[i] - 'a']);
        cout << '\n';
    }
}