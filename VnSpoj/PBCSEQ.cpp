#define fi first
#define se second
#define ii pair<int, int>
#define emp emplace_back
#define maxv 1000000
#include <bits/stdc++.h>
using namespace std;

struct line{
    int x, y;
    bool operator < (const line& a){
        return a.x < x || a.x == x && a.y > y;
    }
};
int n;
vector <line> a;
vector <int> dp, bit(maxv, -1);
void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n; a.resize(n); dp.resize(n, 1);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end());
}

int get(int i){
    int ans = -1;
    for (; i > 0; i -= i & -i)
        if (bit[i] != -1 && (ans == -1 || dp[bit[i]] > dp[ans])) ans = bit[i];
    return ans;
}

void update(int i, int val){
    for (; i <= maxv; i += i & -i)
        if (bit[i] == -1 || dp[bit[i]] < dp[val]) bit[i] = val;
}

int main(){
    setup();
    for (int i = 0; i < n; i++){
        int x = get(a[i].y);
        if (x != -1) dp[i] = dp[x] + 1;
        update(a[i].y, i);
    }
    cout << *max_element(dp.begin(), dp.end());
}
