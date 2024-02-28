import javax.swing.tree.TreeNode;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */

class Solution {
  int res = -1;
  int maxHeight = 0;

  public int findBottomLeftValue(TreeNode root) {
    int maxHeight = findMaxHeight(root, 0);
    dfs(root, 0);
    return res;
  }
  public int findMaxHeight(TreeNode root, int curHeight) {
    if (root == null)
      return curHeight - 1;
    int left = findMaxHeight(root.left, curHeight + 1);
    int right = findMaxHeight(root.right, curHeight + 1);
    return Math.max(left, right);
  }
  public void dfs(TreeNode root, int curHeight) {
    if (root == null) {
      return;
    }
    if (curHeight == maxHeight) {
      if (res != -1) {
        res = root.val;
        return;
      }
    }
    dfs(root.left, curHeight + 1);
    dfs(root.right, curHeight + 1);
    return;
  }
}
