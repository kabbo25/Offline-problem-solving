import java.util.*;

class Solution {
  Map<Integer, List<int[]>> adj = new HashSet<>();
  Map<Integer, List<int[]>> divs = new HashSet<>();

  public boolean canTraverseAllPairs(int[] nums) {
    if (nums.length == 1)
      return true;
    int mx = Arrays.stream(nums).max().getAsInt();
    boolean[] visited = new boolean[mx + 5];
    boolean[] prime = new boolean[mx + 5];
    Arrays.fill(visited, false);
    Arrays.fill(prime, true);

    for (int i = 0; i < nums.length; ++i) {
      if (nums[i] == 1)
        return false;
      visited[nums[i]] = true;
    }
    for (int i = 2; i <= mx; ++i) {
      if (!prime[i])
        continue;
      for (int j = i; j <= mx; j += i) {
        prime[j] = false;
        if (!visited[j])
          continue;
        adj.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
        divs.computeIfAbsent(j, k -> new ArrayList<>()).add(i);
      }
    }
    Arrays.fill(visited, false);
    bfs(nums[0], visited);
    for (int i = 0; i < nums.length; ++i) {
      if (visited[nums[i]])
        continue;
      return false;
    }
    return true;
  }

  public void bfs(int src, boolean[] vis) {
    Queue<Integer> pq = new LinkedList<>();
    pq.add(src);
    while (!pq.isEmpty()) {
      int u = pq.poll();
      if (vis[u] == true)
        continue;
      vis[u] = true;
      // System.out.println(src + " " + u);
      for (int x : divs.get(u)) {
        for (int v : adj.get(x)) {
          if (vis[v])
            continue;
          pq.offer(v);
        }
      }
    }
  }
}

public class Main {
  public static void main(String[] args) {
    Solution obj = new Solution();
    int[] nums = {42, 98, 75, 55};
    System.out.println(obj.canTraverseAllPairs(nums));
  }
}
