#include <bits/stdc++.h>
using namespace std;

struct query{
    char t; int a, b;
};

const int N = 1e5 + 5;
const int ninf = 0xc0c0c0c0;
query que[N]; int bit[N], n;
int seg[N << 2], lo[N << 2], hi[N << 2];

void build(int i, int l, int r){
    seg[i] = ninf; lo[i] = l; hi[i] = r;
    if (l != r){
        int m = (l + r) >> 1;
        build(i << 1, l, m);
        build(i << 1 | 1, m + 1, r);
    }
}

int get_pos(int k){
    int pos = 0;
    for (int p = 1 << 16; p > 0; p >>= 1)
        if (pos + p <= n && bit[pos + p] < k){
            k -= bit[pos + p]; pos += p;
        }
    return pos + 1;
}

void updbit(int i, int t){
    for (; i <= n; i += i & -i) bit[i] += t;
}

void updseg(int i, int pos, int val){
    if (lo[i] > pos || hi[i] < pos) return;
    if (lo[i] == hi[i]){
        seg[i] = val; return;
    }
    updseg(i << 1, pos, val);
    updseg(i << 1 | 1, pos, val);
    seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
}

int get_max(int i, int l, int r){
    if (lo[i] > r || hi[i] < l) return ninf;
    if (lo[i] >= l && hi[i] <= r) return seg[i];
    return max(get_max(i << 1, l, r), 
                get_max(i << 1 | 1, l, r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; build(1, 1, n);
    for (int i = 1; i <= n; i++){
        bit[i]++; int j = i + (i & -i);
        if (j <= n) bit[j] += bit[i];
        cin >> que[i].t >> que[i].a >> que[i].b;
    }
    for (int i = n; i > 0; i--)
        if (que[i].t == 'A')
            updbit(que[i].b = get_pos(que[i].b), -1);
    fill_n(bit + 1, n, 0);
    for (int i = 1; i <= n; i++)
        if (que[i].t == 'A'){
            updbit(que[i].b, 1);
            updseg(1, que[i].b, que[i].a);
        }
        else {
            int l = get_pos(que[i].a);
            int r = get_pos(que[i].b);
            cout << get_max(1, l, r) << '\n';
        }
}