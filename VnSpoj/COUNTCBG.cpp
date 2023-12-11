#include <bits/stdc++.h>
using namespace std;

namespace fastio{
    template <typename T>
    bool read(T &x){
        char c; bool nega = 0; x = 0;
        while (!isdigit(c = getchar()) && c != '-');
        if (!isdigit(c) && c != '-') return false;
        if (c == '-'){
            nega = 1; c = getchar();
        }
        for (; isdigit(c); c = getchar())
            x = (x << 1) + (x << 3) + c - 48;
        if (nega) x = -x; return true;
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

int main(){
    //freopen("countcbg.inp", "r", stdin); 
    int n, cnt, t;
    while (cin >> n){
        cnt = 0; t = (int)sqrt(2 * n);
        for (int i = 2; i <= t; i++)
            if (n * 2 % i == 0 && (i + n * 2 / i) & 1) cnt++;
        fastio::writeln(cnt);
    }
}