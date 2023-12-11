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
  
  static int[] dif = new int[26];

  public static void main(String[] args) {
    int n = fs.nextInt();
    int k = fs.nextInt();
    String s = fs.next();
    String t = fs.next();
    List<Long> holes = new ArrayList<> ();
    long res = 0;
    int cnt = 0;
    for (int i = 0; i < n; ) {
      
      if (s.charAt(i) == t.charAt(i)) {
        boolean flag = i > 0;
        long sum = 0;
        while (i < n && s.charAt(i) == t.charAt(i)) {
          sum += fs.nextInt(); i++;
        }
        if (flag && i < n) holes.add(sum);
      } else {
        cnt++;
        while (i < n) {
          dif[s.charAt(i) - 'a']++;
          dif[t.charAt(i) - 'a']--;
          res += fs.nextInt(); i++;
          boolean good = true;
          for (int c = 0; c < 26; c++) {
            if (dif[c] != 0) {
              good = false;
              break;
            }
          }
          if (good && (i == n || s.charAt(i) == t.charAt(i))) {
            break;
          }
        }
      }
    }
    // Collections.sort(holes);
    // for (int i = 0; i < cnt - k; i++) {
      // res += holes.get(i);
    // }
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