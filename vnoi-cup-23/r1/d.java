import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Collections;

public class Main {
  static FastScanner fs = new FastScanner();
  static PrintWriter pw = new PrintWriter(System.out);
  
  static final int N = 1000005;
  
  static int[][] a;
  static int[] bit = new int[N];
  static int n, m;
  static List<Integer>[] rmv = new List[N];
  
  static void add(int i, int v) {
    for (i++; i > 0; i -= i & -i) {
      bit[i] += v;
    }
  }
  
  static int get(int i) {
    int res = 0;
    for (i = Math.max(i, 0) + 1; i <= m; i += i & -i) {
      res += bit[i];
    }
    return res;
  }

  public static void main(String[] args) {
    int _n = fs.nextInt();
    int _m = fs.nextInt();
    if (_n <= _m) {
      n = _n; m = _m;
      a = new int[n][m];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          a[i][j] = fs.nextInt();
        }
      }
    } else {
      n = _m; m = _n;
      a = new int[n][m];
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          a[j][m - i - 1] = fs.nextInt();
        }
      }
    }
    long res = 0;
    for (int r1 = 0; r1 < n; r1++) {
      for (int r2 = r1 + 1; r2 < n; r2++) {
        for (int c = 0; c < m; c++) {
          rmv[c] = new ArrayList<Integer> ();
          bit[c + 1] = 0;
        }
        for (int c = 0; c < m; c++) {
          for (int p : rmv[c]) {
            add(p, -1);
          }
          if (a[r1][c] >= r2 - r1) {
            res += get(c - a[r2][c]);
          }
          if (a[r2][c] >= r2 - r1) {
            add(c, 1);
            if (a[r1][c] + c + 1 < m)
              rmv[a[r1][c] + c + 1].add(c);
          }
        }
      }
    }
    pw.println(res);
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