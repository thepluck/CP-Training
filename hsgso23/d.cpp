#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

struct node {
  int ans[2][2];

  node() {
    memset(ans, 0x3f, sizeof ans);
  }

  node operator + (const node &o) const {
    node res;
    for (int a = 0; a < 2; a++)
      for (int b = 0; b < 2; b++)
        res.ans[a][b] = min
        (max(ans[a][0], o.ans[0][b]),
        max(ans[a][1], o.ans[1][b]));
    return res;
  }

  void pull(const node &x, const node &y) {
    for (int a = 0; a < 2; a++)
      for (int b = 0; b < 2; b++)
        ans[a][b] = min
        (max(x.ans[a][0], y.ans[0][b]),
        max(x.ans[a][1], y.ans[1][b]));
  }
} seg[N * 2], res;

struct query {
  int x1, y1, x2, y2, l, r, id;

  bool operator < (const query &o) const {
    return l > o.l;
  }
} que[N];

int val[2][N], pos[N * 2];
bool ans[N];

void update(int i, int l, int r, int x, int y) {
  if (l == r) {
    seg[i].ans[x][x] = val[x][y];
    seg[i].ans[0][1] = seg[i].ans[1][0] =
    max(seg[i].ans[0][0], seg[i].ans[1][1]);
    return;
  }
  int m = (l + r) / 2;
  if (m >= y) update(i + 1, l, m, x, y);
  else update(i + (m - l + 1) * 2, m + 1, r, x, y);
  seg[i].pull(seg[i + 1], seg[i + (m - l + 1) * 2]);
}

void get(int i, int l, int r, int x, int y) {
  if (l >= x && r <= y) {
    res = res + seg[i]; return;
  }
  int m = (l + r) / 2;
  if (m >= x) get(i + 1, l, m, x, y);
  if (m < y) get(i + (m - l + 1) * 2, m + 1, r, x, y);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int x = 0; x < 2; x++)
    for (int y = 1; y <= n; y++) {
      cin >> val[x][y]; pos[val[x][y]] = y;
    }
  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> que[i].x1 >> que[i].y1;
    cin >> que[i].x2 >> que[i].y2;
    cin >> que[i].l >> que[i].r;
    que[i].id = i;
  }
  sort(que + 1, que + q + 1);
  for (int l = 2 * n, i = 1; l > 0; l--) {
    update(1, 1, n, val[1][pos[l]] == l, pos[l]);
    while (i <= q && que[i].l == l) {
      res.ans[0][0] = res.ans[1][1] = 0;
      res.ans[0][1] = res.ans[1][0] = INF;
      if (que[i].y1 > que[i].y2) {
        swap(que[i].x1, que[i].x2);
        swap(que[i].y1, que[i].y2);
      }
      get(1, 1, n, que[i].y1, que[i].y2);
      ans[que[i].id] = res.ans[que[i].x1][que[i].x2] <= que[i].r;
      i++;
    }
  }
  for (int i = 1; i <= q; i++)
    cout << (ans[i] ? "YES\n" : "NO\n");
}