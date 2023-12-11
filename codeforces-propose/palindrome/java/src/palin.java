import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class palin {
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter pw = new PrintWriter(System.out);
        int t = fs.nextInt();
        for (int tc = 0; tc < t; tc++) {
            int n = fs.nextInt();
            String s = fs.nextString();
            int[] pal = new int[n + 1];
            TreeSet<Integer> set = new TreeSet<>();
            ArrayList<ArrayList<Integer>> rmv = new ArrayList<>();
            Long ans = 0L;
            /// even manacher
            for (int i = 0, l = 0, r = 0; i < n; i++) {
                pal[i] = i >= r ? 0 : Math.min(r - i, pal[l + r - i]);
                while (i - pal[i] - 1 >= 0 && i + pal[i] < n
                        && s.charAt(i - pal[i] - 1) == s.charAt(i + pal[i])) {
                    pal[i]++;
                }
                if (i + pal[i] > r) {
                    l = i - pal[i];
                    r = i + pal[i];
                }

                rmv.add(new ArrayList<>());
                rmv.get(i - pal[i]).add(i);
            }
            for (int i = n - 1; i >= 0; i--) {
                pal[i] = 0;
                if (!set.isEmpty()) {
                    pal[i] = pal[2 * set.first() - i] + 1;
                }
                ans += pal[i];
                set.add(i);
                for (Integer j : rmv.get(i)) {
                    set.remove(j);
                }
            }
            pw.println(ans);
        }
        pw.close();
    }
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        String nextString() {
            return next();
        }
    }
}
