#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    if (N & 1) cout << 1ll * (N / 2 + 1) * (N / 2 + 1) << '\n';
    else cout << 1ll * (N / 2 + 1) * (N / 2) << '\n';
    if (N <= 23) {
        auto cost = [&](int mask) {
            int sum[2], cost = 0;
            vector<int> pos;
            pos.push_back(-1);
            for (int i = 0; i < N; i++)
                if (mask >> i & 1)
                    pos.push_back(i);
            pos.push_back(N);
            sum[0] = sum[1] = 0;
            for (int i = 1; i + 1 < pos.size(); i++) {
                sum[i & 1] += pos[i] - pos[i - 1];
                cost += sum[i & 1] * (pos[i + 1] - pos[i]);
            }
            return cost;
        };

        int max_cost = 0;
        for (int mask = 0; mask < (1 << N); mask++)
            max_cost = max(max_cost, cost(mask));
        int cnt = 0;
        for (int mask = 0; mask < (1 << N); mask++)
            if (cnt < 100 && max_cost == cost(mask)) {
                cnt++;
                for (int i = N - 1; i >= 0; i--)
                    if (mask >> i & 1) cout << 'r';
                    else cout << 'b';
                cout << '\n';
            }
        return 0;
    }
    if (N & 1) {
        int cnt = 2;
        for (int i = 1; i <= N / 2; i++)
            cout << 'b';
        cout << 'r';
        for (int i = 1; i <= N / 2; i++)
            cout << 'b';
        cout << '\n';
        for (int i = 1; i < N / 2; i++)
            cout << 'b';
        cout << 'r';
        for (int i = 1; i <= N / 2; i++)
            cout << 'b';
        cout << "r\n";
        for (int i = N - 1; i > N / 2; i--) {
            if (cnt == 100) break;
            for (int j = 1; j < N / 2; j++)
                cout << 'b';
            cout << 'r';
            for (int j = N / 2 + 1; j <= N; j++)
                if (j == i || j == i + 1)
                    cout << 'r';
                else cout << 'b';
            cout << '\n'; cnt++;
        }
        for (int i = N / 2 - 1; i > 0; i--) {
            if (cnt == 100) break;
            for (int j = 1; j < i; j++)
                cout << 'b';
            cout << 'r';
            for (int j = i + 1; j + 2 <= N; j++)
                cout << 'b';
            cout << "rb\n";
            cnt++;
            if (cnt == 100) break;
            for (int j = 1; j < i; j++)
                cout << 'b';
            cout << 'r';
            for (int j = i + 1; j + 3 <= N; j++)
                cout << 'b';
            cout << "rbr\n";
            cnt++;
            if (cnt == 100) break;
            for (int j = 1; j < i; j++)
                cout << 'b';
            cout << 'r';
            for (int j = i + 1; j + 3 <= N; j++)
                cout << 'b';
            cout << "rrr\n";
            cnt++;
            for (int len = 4; len <= N - i; len++) {
                if (cnt == 100) break;
                for (int j = 1; j < i; j++)
                    cout << 'b';
                cout << 'r';
                for (int j = i + 1; j + len <= N; j++)
                    cout << 'b';
                cout << "rbr";
                for (int j = 1; j <= len - 3; j++)
                    cout << 'b';
                cout << '\n'; cnt++;
                if (cnt == 100) break;
                for (int j = 1; j < i; j++)
                    cout << 'b';
                cout << 'r';
                for (int j = i + 1; j + len <= N; j++)
                    cout << 'b';
                cout << "rr";
                for (int j = 1; j <= len - 3; j++)
                    cout << 'b';
                cout << "r\n"; cnt++;
                if (cnt == 100) break;
                for (int k = 1; k <= len - 3; k++) {
                    if (cnt == 100) break;
                    for (int j = 1; j < i; j++)
                        cout << 'b';
                    cout << 'r';
                    for (int j = i + 1; j + len <= N; j++)
                        cout << 'b';
                    cout << "rr";
                    for (int j = N - len + 3; j <= N; j++)
                        if (j == N - k || j == N - k + 1)
                            cout << 'r';
                        else cout << 'b';
                    cout << '\n'; cnt++;
                }
            }
        }
    } else {
        int cnt = 3;
        for (int i = 1; i <= N / 2; i++)
            cout << 'b';
        cout << 'r';
        for (int i = 1; i < N / 2; i++)
            cout << 'b';
        cout << '\n';
        for (int i = 1; i < N / 2; i++)
            cout << 'b';
        cout << 'r';
        for (int i = 1; i <= N / 2; i++)
            cout << 'b';
        cout << "\n";
        for (int i = 1; i < N / 2; i++)
            cout << 'b';
        cout << 'r';
        for (int i = 1; i < N / 2; i++)
            cout << 'b';
        cout << "r\n";
        for (int i = N - 1; i > N / 2; i--) {
            if (cnt == 100) break;
            for (int j = 1; j < N / 2; j++)
                cout << 'b';
            cout << 'r';
            for (int j = N / 2 + 1; j <= N; j++)
                if (j == i || j == i + 1)
                    cout << 'r';
                else cout << 'b';
            cout << '\n'; cnt++;
        }
        for (int i = N / 2 - 1; i > 0; i--) {
            if (cnt == 100) break;
            for (int j = 1; j < i; j++)
                cout << 'b';
            cout << 'r';
            for (int j = i + 1; j + 2 <= N; j++)
                cout << 'b';
            cout << "br\n";
            cnt++;
            if (cnt == 100) break;
            for (int j = 1; j < i; j++)
                cout << 'b';
            cout << 'r';
            for (int j = i + 1; j + 2 <= N; j++)
                cout << 'b';
            cout << "rb\n";
            cnt++;
            if (cnt == 100) break;
            for (int j = 1; j < i; j++)
                cout << 'b';
            cout << 'r';
            for (int j = i + 1; j + 2 <= N; j++)
                cout << 'b';
            cout << "rr\n";
            cnt++;
            if (cnt == 100) break;
            for (int j = 1; j < i; j++)
                cout << 'b';
            cout << 'r';
            for (int j = i + 1; j + 3 <= N; j++)
                cout << 'b';
            cout << "rbr\n";
            cnt++;
            if (cnt == 100) break;
            for (int j = 1; j < i; j++)
                cout << 'b';
            cout << 'r';
            for (int j = i + 1; j + 3 <= N; j++)
                cout << 'b';
            cout << "rrb\n";
            cnt++;
            if (cnt == 100) break;
            for (int j = 1; j < i; j++)
                cout << 'b';
            cout << 'r';
            for (int j = i + 1; j + 3 <= N; j++)
                cout << 'b';
            cout << "rrr\n";
            cnt++;
            for (int len = 4; len <= N - i; len++) {
                if (cnt == 100) break;
                for (int j = 1; j < i; j++)
                    cout << 'b';
                cout << 'r';
                for (int j = i + 1; j + len <= N; j++)
                    cout << 'b';
                cout << "rbr";
                for (int j = 1; j <= len - 3; j++)
                    cout << 'b';
                cout << '\n'; cnt++;
                if (cnt == 100) break;
                for (int j = 1; j < i; j++)
                    cout << 'b';
                cout << 'r';
                for (int j = i + 1; j + len <= N; j++)
                    cout << 'b';
                cout << "rr";
                for (int j = 1; j <= len - 2; j++)
                    cout << 'b';
                cout << '\n';
                cnt++;
                if (cnt == 100) break;
                for (int j = 1; j < i; j++)
                    cout << 'b';
                cout << 'r';
                for (int j = i + 1; j + len <= N; j++)
                    cout << 'b';
                cout << "rr";
                for (int j = 1; j <= len - 3; j++)
                    cout << 'b';
                cout << "r\n"; cnt++;
                if (cnt == 100) break;
                for (int k = 1; k <= len - 3; k++) {
                    if (cnt == 100) break;
                    for (int j = 1; j < i; j++)
                        cout << 'b';
                    cout << 'r';
                    for (int j = i + 1; j + len <= N; j++)
                        cout << 'b';
                    cout << "rr";
                    for (int j = N - len + 3; j <= N; j++)
                        if (j == N - k || j == N - k + 1)
                            cout << 'r';
                        else cout << 'b';
                    cout << '\n'; cnt++;
                }
            }
        }
    }
}