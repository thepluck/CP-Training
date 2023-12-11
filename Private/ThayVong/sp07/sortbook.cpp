#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N], n;
bitset <N> mark;

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

int main(){
    freopen("sortbook.inp", "r", stdin);
    freopen("sortbook.out", "w", stdout);
    read(n); int x = n; set <int> s;
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = n; i >= 1; i--)
        if (a[i] == x){
            x--; mark[i] = true;
        }
    writeln(x);
    for (int i = n; i >= 1; i--)
        if (!mark[i]) s.insert(a[i]);
    for (auto it = s.rbegin(); it != s.rend(); it++){
        write(*it); putchar(' ');
    }
}