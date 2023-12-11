#include <bits/stdc++.h>
using namespace std;

namespace fastio{
    template <typename T>
    void read(T &x){
        char c; bool nega = 0; x = 0;
        while (!isdigit(c = getchar()) && c != '-');
        if (c == '-'){
            nega = 1; c = getchar();
        }
        for (; isdigit(c); c = getchar())
            x = (x << 1) + (x << 3) + c - 48;
        if (nega) x = -x;
    }

    template <typename T>
    void writep(T x){
        if (x > 9) writep(x / 10);
        putchar(x % 10 + 48);
    }

    template <typename T>
    void write(T x){
        if (x < 0){
            x = -x; putchar('-');
        }
        writep(x);
    }

    template <typename T>
    void writeln(T x){
        write(x); putchar('\n');
    }
}

using namespace fastio;

const int N = (1 << 20) + 5;
int a[N], n, l, r, cnt[N];
pair <int, int> qq[N];

int get_num(int lim){
    if (lim == 0) return 0;
    int num = 0, res = 0;
    fill(cnt + 1, cnt + n + 1, 0);
    for (int i = 1, k = 0; i <= n; i++){
        while (k < n && num < lim) 
            num += ++cnt[a[++k]] == 1;
        while (k < n && cnt[a[k + 1]] > 0)
            ++cnt[a[++k]];
        res += k - i + 1;
        num -= --cnt[a[i]] == 0;
    }
    return res;
}

int main(){ 
    read(n); read(l); read(r);
    for (int i = 1; i <= n; i++){
        cin >> qq[i].first;
        qq[i].second = i;
    }
    sort(qq + 1, qq + n + 1);
    qq[0].first = INT_MIN;
    for (int i = 1; i <= n; i++)
        if (qq[i].first > qq[i - 1].first)
            a[qq[i].second] = a[qq[i - 1].second] + 1;
        else a[qq[i].second] = a[qq[i - 1].second];
    writeln(get_num(r) - get_num(l - 1));
}   