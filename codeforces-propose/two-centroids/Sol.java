import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Sol {
  static FastScanner fs = new FastScanner();
  static PrintWriter pw = new PrintWriter(System.out);

  static final int N = 500005;
  static final int LOG = 19;

  static int[][] par = new int[LOG][N];
  static ArrayList<Integer>[] adj = new ArrayList[N];
  static int[] bit = new int[N];
  static int[] dep = new int[N];
  static int[] tin = new int[N];
  static int[] tout = new int[N];
  static int timer;

  static void dfs(int u) {
    tin[u] = ++timer;
    dep[u] = dep[par[0][u]] + 1;
    for (int k = 1; k < LOG; k++) {
      par[k][u] = par[k - 1][par[k - 1][u]];
    }
    for (Integer v : adj[u]) {
      dfs(v);
    }
    tout[u] = timer;
  }

  static void add(int u) {
    for (int i = tin[u]; i < N; i += i & -i) {
      bit[i]++;
    }
  }

  static int get(int u) {
    int res = 0;
    for (int i = tout[u]; i > 0; i -= i & -i) {
      res += bit[i];
    }
    for (int i = tin[u] - 1; i > 0; i -= i & -i) {
      res -= bit[i];
    }
    return res;
  }

  static int jump(int u, int d) {
    for (int k = 0; k < LOG; k++) {
      if ((d >> k & 1) > 0) {
        u = par[k][u];
      }
    }
    return u;
  }

  static boolean cover(int u, int v) {
    return tin[u] <= tin[v] && tin[v] <= tout[u];
  }
  public static void solve() {
    int n = fs.nextInt();

    /// reset
    timer = 0;
    for (int i = 1; i <= n; i++) {
      bit[i] = 0;
      adj[i] = new ArrayList<>();
    }

    for (int i = 2; i <= n; i++) {
      par[0][i] = fs.nextInt();
      adj[par[0][i]].add(i);
    }

    dfs(1); add(1);

    int cen = 1, maxSize = 0;

    for (int u = 2; u <= n; u++) {
      add(u);
      if (cover(cen, u)) {
        int v = jump(u, dep[u] - dep[cen] - 1);
        int size = get(v);
        if (size >= (u + 1) / 2) {
          cen = v; maxSize = u / 2;
        } else {
          maxSize = Math.max(maxSize, size);
        }
      } else {
        int size = get(cen);
        if (size < (u + 1) / 2) {
          cen = par[0][cen]; maxSize = u / 2;
        } else {
          maxSize = Math.max(maxSize, u - size);
        }
      }
      pw.print(u - 2 * maxSize + (u == n ? "\n" : " "));
    }
  }

  public static void main(String[] args) {
    int t = fs.nextInt();
    for (int tc = 0; tc < t; tc++) {
      solve();
    }
    pw.close();
  }

  /// fast input reader
  static class FastScanner {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer("");

    String next() {
      while (!st.hasMoreTokens()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(next());
    }

    long nextLong() {
      return Long.parseLong(next());
    }
  }
}
