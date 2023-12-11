#include <bits/stdc++.h>

char read_char() {
    static char buf[1000000];
    static char *p = buf, *q = buf;
    return p == q && (q = (p = buf) +
        fread(buf, 1, 1000000, stdin),
        p == q) ? EOF : *p++;
}

int read_int() {
    char c = read_char();
    while (c != '-' && !isdigit(c))
        c = read_char();
    bool neg = 0;
    if (c == '-') {
        neg = 1; c = read_char();
    }
    int res = c - '0';
    while (isdigit(c = read_char()))
        res = res * 10 + c - '0';
    return neg ? -res : res;
}