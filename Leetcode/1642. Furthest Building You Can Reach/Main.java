class Solution {
  public int furthestBuilding(int[] heights, int bricks, int ladders) {
    int lo = Integer.MAX_VALUE;
    int hi = Integer.MIN_VALUE;
    for (int i = 0; i + 1 < heights.length; ++i) {
      int climb = heights[i + 1] - heights[i];
      if (climb <= 0)
        continue;
      lo = Math.min(lo, climb);
      hi = Math.max(climb, hi);
    }
    if (lo == Integer.MAX_VALUE)
      return heights.length - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int[] result = Solve(heights, bricks, ladders, mid);
      int indexReached = result[0];
      int ladderRemaining = result[1];
      int bricksRemaining = result[2];
      if (indexReached == heights.length - 1)
        return heights.length - 1;
      if (ladderRemaining > 0) {
        hi = mid - 1;
        continue;
      }
      int nextclimb = heights[indexReached + 1] - heights[indexReached];
      if (nextclimb > bricksRemaining && mid > bricksRemaining)
        return indexReached;
      else
        lo = mid + 1;
    }
    return -1;
  }
  public int[] Solve(int[] heights, int bricks, int ladders, int k) {
    int laddersUsedOnThreshold = 0;
    for (int i = 0; i < heights.length - 1; ++i) {
      int climb = heights[i + 1] - heights[i];
      if (climb <= 0)
        continue;
      if (climb >= k) {
        ladders--;
        if (climb == k)
          laddersUsedOnThreshold++;
      } else
        bricks -= climb;
      if (ladders < 0) {
        if (laddersUsedOnThreshold > 0) {
          laddersUsedOnThreshold--;
          ladders++;
          bricks -= k;
        } else
          return new int[] {i, ladders, bricks};
      }
      if (bricks < 0) {
        return new int[] {i, ladders, bricks};
      }
    }
    return new int[] {heights.length - 1, ladders, bricks};
  }
}
public class Main {
  public static void main(String[] args) {
    Solution obj = new Solution();
    int[] heights = {4, 2, 7, 6, 9, 14, 12};
    int bricks = 5;
    int ladders = 1;
    System.out.println(obj.furthestBuilding(heights, bricks, ladders));
  }
}
