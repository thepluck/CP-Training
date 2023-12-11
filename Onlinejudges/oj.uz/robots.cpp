#include <bits/stdc++.h>
//#include <robots.h>
using namespace std;
 
const int T = 1000005;
 
struct item {
    int w, s;
} v[T];
 
int putaway(int a, int b, int t,
int x[], int y[], int w[], int s[]) {
    int maxw = *max_element(x, x + a);
    int maxs = *max_element(y, y + b);
    for (int i = 0; i < t; i++) {
        if (a && w[i] < maxw) continue;
        if (b && s[i] < maxs) continue;
        return -1;
    }
    int lo = 0, hi = t;
    for (int i = 0; i < t; i++)
        v[i] = {w[i], s[i]};
    sort(v, v + t,
    [](item p, item q) {
        return p.w < q.w ||
        (p.w == q.w && p.s < q.s);
    });
    sort(x, x + a); sort(y, y + b);
    while (lo < hi) {
        priority_queue <int> pq;
        int mi = (lo + hi) / 2, j = 0;
        for (int i = 0; i < a; i++) {
            while (j < t && v[j].w < x[i])
                pq.push(v[j++].s);
            int k = mi;
            while (pq.size() && k) {
                k--; pq.pop();
            }
        }
        while (j < t) pq.push(v[j++].s);
        for (int i = b - 1; ~i; i--) {
            int k = mi;
            while (pq.size() && k
            && pq.top() < y[i]) {
                k--; pq.pop();
            }
        }
        if (pq.size()) lo = mi + 1;
        else hi = mi;
    }
    return hi;
}

/*int main() {
    int x[] = {6, 2, 9};
    int y[] = {4, 7};
    int w[] = {4, 8, 2, 7, 1, 5, 3, 8, 7, 10};
    int s[] = {6, 5, 3, 9, 8, 1, 3, 7, 6, 5};
    cout << putaway(3, 2, 10, x, y, w, s);
}*/