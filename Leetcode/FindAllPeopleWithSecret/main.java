
import java.awt.Point;
import java.util.*;

class Solution {
  public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
    ArrayList<ArrayList<Point>> adj = new ArrayList<>();
    boolean[] visited = new boolean[n + 1];
    for (int i = 0; i <= n; i++) {
      adj.add(new ArrayList<>());
    }
    Arrays.fill(visited, false);
    for (int[] person : meetings) {
      adj.get(person[0]).add(new Point(person[1], person[2]));
      adj.get(person[1]).add(new Point(person[0], person[2]));
    }
    // distance,time,node
    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
    List<Integer> res = new ArrayList<>();
    pq.add(new int[] {0, 0});
    pq.add(new int[] {0, firstPerson});
    while (!pq.isEmpty()) {
      int[] curr = pq.poll();
      int time = curr[0];
      int node = curr[1];
      if (visited[node]) {
        continue;
      }
      visited[node] = true;
      res.add(node);
      for (Point next : adj.get(node)) {
        if (visited[next.x])
          continue;
        if (next.y >= time) {
          pq.add(new int[] {next.y, next.x});
        }
      }
    }

    return res;
  }
}
