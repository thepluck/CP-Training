#include "fakecoinlib.h"
#include <bits/stdc++.h>

using namespace std;

int A[1005];

int solve3(int res, vector<int> coin) {
    if (coin.size() == 1) return coin[0];
    if (coin.size() == 2) {
        A[1] = coin[0]; A[2] = coin[1];
        int tmp = compare(A, 1);
        if (tmp == 0) return -1;
        if (tmp == res) return coin[0];
        return coin[1];
    }
    int l = (coin.size() + 2) / 3;
    for (int i = 0; i < l * 2; i++)
        A[i + 1] = coin[i];
    int tmp = compare(A, l);
    vector<int> new_coin;
    if (tmp == 0) {
        for (int i = l * 2; i < coin.size(); i++)
            new_coin.push_back(coin[i]);
    } else if (tmp == res) {
        for (int i = 0; i < l; i++)
            new_coin.push_back(coin[i]);
    } else {
        for (int i = l; i < l * 2; i++)
            new_coin.push_back(coin[i]);
    }
    return solve3(res, new_coin);
}

void solve1(vector<int> heavy_coin, vector<int> light_coin, vector<int> real_coin) {
    if (heavy_coin.size() == 0)
        return answer(solve3(-1, light_coin), -1);
    if (light_coin.size() == 0)
        return answer(solve3(1, heavy_coin), 1);
    int l = (heavy_coin.size() + 2) / 3;
    int r = (light_coin.size() + 2) / 3;
    int ptr = 0;
    for (int i = 0; i < l; i++)
        A[++ptr] = heavy_coin[i];
    for (int i = 0; i < r; i++)
        A[++ptr] = light_coin[i];
    for (int i = l; i < 2 * l - 1; i++)
        A[++ptr] = heavy_coin[i];
    for (int i = r; i < 2 * r - 1; i++)
        A[++ptr] = light_coin[i];
    A[++ptr] = real_coin[0];
    A[++ptr] = real_coin[1];
    int res = compare(A, l + r);
    vector<int> new_heavy_coin, new_light_coin;
    if (res == 0) {
        for (int i = 2 * l - 1; i < heavy_coin.size(); i++)
            new_heavy_coin.push_back(heavy_coin[i]);
        for (int i = 2 * r - 1; i < light_coin.size(); i++)
            new_light_coin.push_back(light_coin[i]);
    } else if (res == 1) {
        for (int i = 0; i < l; i++)
            new_heavy_coin.push_back(heavy_coin[i]);
        for (int i = r; i < 2 * r - 1; i++)
            new_light_coin.push_back(light_coin[i]);
    } else {
        for (int i = l; i < 2 * l - 1; i++)
            new_heavy_coin.push_back(heavy_coin[i]);
        for (int i = 0; i < r; i++)
            new_light_coin.push_back(light_coin[i]);
    }
    solve1(new_heavy_coin, new_light_coin, real_coin);
}

void solve2(vector<int> coin, vector<int> real_coin) {
    if (coin.size() == 1) {
        A[1] = coin[0]; A[2] = real_coin[0];
        return answer(coin[0], compare(A, 1));
    }
    if (coin.size() == 2) {
        A[1] = coin[0]; A[2] = coin[1];
        A[3] = real_coin[0]; A[4] = real_coin[1];
        int res = compare(A, 2);
        return answer(solve3(res, coin), res);
    }
    int l = (2 * coin.size() + 2) / 3;
    for (int i = 0; i < l; i++) {
        A[i + 1] = coin[i];
        A[i + l + 1] = real_coin[i];
    }
    int res = compare(A, l);
    vector<int> new_coin;
    if (!res) {
        for (int i = l; i < coin.size(); i++)
            new_coin.push_back(coin[i]);
        solve2(new_coin, real_coin);
    } else {
        for (int i = 0; i < l; i++)
            new_coin.push_back(coin[i]);
        answer(solve3(res, new_coin), res);
    }
}



void solve() {
    int n = get_n();
    if (n <= 6) {
        int X[10];
        for (int i = 2; i <= n; i++) {
            A[1] = 1; A[2] = i;
            X[i] = compare(A, 1);
        }
        if (count(X + 2, X + n + 1, 1) == n - 1)
            return answer(1, 1);
        if (count(X + 2, X + n + 1, -1) == n - 1)
            return answer(1, -1);
        for (int i = 2; i <= n; i++)
            if (X[i]) return answer(i, -X[i]);
    }
    vector<int> coin1, coin2, coin3;
    int l = (n + 2) / 3;
    for (int i = 1; i <= l; i++) {
        coin1.push_back(i);
        A[i] = i; A[i + l] = i + l;
    }
    for (int i = l + 1; i <= 2 * l; i++)
        coin2.push_back(i);
    for (int i = 2 * l + 1; i <= n; i++)
        coin3.push_back(i);
    int res = compare(A, l);
    if (res == 1) solve1(coin1, coin2, coin3);
    else if (res == -1) solve1(coin2, coin1, coin3);
    else {
        for (int i = l + 1; i <= 2 * l; i++)
            coin1.push_back(i);
        solve2(coin3, coin1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = get_T();
    while (T--) solve();
    
}