//https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_e
#include <bits/stdc++.h>
using namespace std;

char s[1050];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j < (1 << m); j++)
            if ((i & -i) == (j & -j)) s[j] = '1';
            else s[j] = '0';
        puts(s + 1);
    }
}