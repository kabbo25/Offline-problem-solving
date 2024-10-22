#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// TreeNode structure definition
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  long long kthLargestLevelSum(TreeNode *root, int k) {
    // Your solution implementation here
    queue<TreeNode *> pq;
    vector<int64_t> sorted_sum;
    pq.push(root);
    while (pq.size()) {
      int64_t cur_sum = 0;
      int sz=pq.size();
      for (int i(0); i < sz; ++i) {
        auto cur_node = pq.front();
        pq.pop();
        cur_sum += cur_node->val;
        if (cur_node->left)
          pq.push(cur_node->left);
        if (cur_node->right)
          pq.push(cur_node->right);
      }
      cout<<cur_sum<<endl;
      sorted_sum.emplace_back(cur_sum);
    }
    sort(sorted_sum.rbegin(), sorted_sum.rend());
    return k >= (int)sorted_sum.size() ? -1 : sorted_sum[k - 1];
  }
};

// Function to create tree from level order traversal
TreeNode *createTree(vector<int> &values) {
  if (values.empty())
    return nullptr;

  TreeNode *root = new TreeNode(values[0]);
  queue<TreeNode *> q;
  q.push(root);

  int i = 1;
  while (!q.empty() && i < values.size()) {
    TreeNode *current = q.front();
    q.pop();

    // Left child
    if (i < values.size()) {
      if (values[i] != -1) { // Using -1 to represent null nodes
        current->left = new TreeNode(values[i]);
        q.push(current->left);
      }
      i++;
    }

    // Right child
    if (i < values.size()) {
      if (values[i] != -1) { // Using -1 to represent null nodes
        current->right = new TreeNode(values[i]);
        q.push(current->right);
      }
      i++;
    }
  }
  return root;
}

// Function to free memory
void deleteTree(TreeNode *root) {
  if (root == nullptr)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main() {
  // Test case
  vector<int> values = {5, 8, 9, 2, 1, 3, 7, 4, 6};
  int k = 2;

  // Create the tree
  TreeNode *root = createTree(values);

  // Create solution object and call the function
  Solution solution;
  long long result = solution.kthLargestLevelSum(root, k);

  // Print result
  cout << "kth Largest Level Sum: " << result << endl;

  // Clean up memory
  deleteTree(root);

  return 0;
}