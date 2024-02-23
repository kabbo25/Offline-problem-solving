class Solution {
  public int findJudge(int n, int[][] trust) {
    int[] indegree = new int[n + 1];
    int[] outdegree = new int[n + 1];
    for (int[] ele : trust) {
      indegree[ele[1]]++;
      outdegree[ele[0]]++;
    }
    int judge = -1;
    for (int i = 1; i <= n; ++i) {
      if (indegree[i] == n - 1 && outdegree[i] == 0) {
        judge = i;
      }
    }
    return judge;
  }

  public static void main(String[] args) { System.out.println("hello"); }
}
