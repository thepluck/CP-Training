#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct block {
    ll val;
    block *prev, *next;

    block(ll val): val(val) {
        prev = next = nullptr;
    }
};

using blockpt = block*;

struct compare {
    bool operator () (const blockpt &x,
    const blockpt &y) const {
        return abs(x->val) != abs(y->val) ?
        abs(x->val) < abs(y->val) : x < y;
    }
};

const int N = 3e5 + 5;

set <block*, compare> blocks;
int a[N]; block *b[N];

bool sign(const int &x) {
    return x <= 0 ? 0 : 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, m = 0, p = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; cin >> a[i++]);
    for (int i = 1; i <= n; ) {
        int j = i; ll sum = 0;
        while (j <= n && sign(a[i])
        == sign(a[j])) sum += a[j++];
        if (sum > 0 || m > 0)
            b[m++] = new block(sum);
        i = j; p += sum > 0;
    }
    if (m > 0 && b[m - 1]->val < 0) m--;
    for (int i = 0; i < m; i++)
        blocks.insert(b[i]);
    for (int i = 1; i < m; i++) {
        b[i]->prev = b[i - 1];
        b[i - 1]->next = b[i];
    }
    while (p > k && blocks.size()) {
        blockpt it = *blocks.begin();
        blocks.erase(it);
        if (it->val > 0) p--;
        if (it->prev) {
            blocks.erase(it->prev);
            if (it->prev->val > 0) p--;
            it->val += it->prev->val;
            it->prev = it->prev->prev;
            if (it->prev)
                it->prev->next = it;
        }
        if (it->next) {
            blocks.erase(it->next);
            if (it->next->val > 0) p--;
            it->val += it->next->val;
            it->next = it->next->next;
            if (it->next)
                it->next->prev = it;
        }
        if (it->val <= 0) {
            if (!it->prev)
                it->next->prev = 0;
            else if (!it->next)
                it->prev->next = 0;
            else blocks.insert(it);
        }
        else {
            blocks.insert(it); p++;
        }
    }
    ll res = 0;
    for (auto it : blocks)
        res += max(0ll, it->val);
    cout << res << '\n';
}