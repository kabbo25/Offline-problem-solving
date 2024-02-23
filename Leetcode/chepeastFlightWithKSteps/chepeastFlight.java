import java.awt.*;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
  ArrayList<ArrayList<Point>> am;
  int[][] dp;

  public int findCheapestPrice(int n, int[][] flights, int src, int dst,
                               int k) {
    am = new ArrayList<>(n);
    dp = new int[n][k + 2];
    for (int i = 0; i < n; ++i) {
      am.add(new ArrayList<>());
      Arrays.fill(dp[i], -888);
    }

    for (int i = 0; i < flights.length; ++i) {

      int[] node = flights[i];
      am.get(node[0]).add(new Point(node[1], node[2]));
    }
    // System.out.println(am.get(0));
    return recur(src, dst, k + 1);
  }

  public int recur(int src, int dst, int k) {
    if (k < 0) {
      return -1;
    }
    if (src == dst) {
      return 0;
    }

    if (dp[src][k] != -888)
      return dp[src][k];
    int min = Integer.MAX_VALUE;
    for (Point p : am.get(src)) {
      int cost = recur(p.x, dst, k - 1);
      if (cost != -1) {
        min = Math.min(min, p.y + cost);
      }
    }
    dp[src][k] = min == Integer.MAX_VALUE ? -1 : min;
    return dp[src][k];
  }
}
