#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
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
    map<int, int> mp;
    map<int, int64_t> sum;
    queue<TreeNode *> pq;
    pq.push(root);
    while (pq.size()) {
      auto cur = pq.front();
      pq.pop();
      sum[mp[cur->val]] += cur->val;
      if (cur->left != nullptr) {
        mp[cur->left->val] = mp[cur->val] + 1;
        pq.push(cur->left);
      }
      if (cur->right != nullptr) {
        mp[cur->right->val] = mp[cur->val] + 1;
        pq.push(cur->right);
      }
    }
    vector<int64_t> sorted_sum;
    for (auto [a, b] : sum) {
      sorted_sum.emplace_back(b);
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
  vector<int> values = {5, 8, 9, 2, 1, 3, 7};
  int k = 4;

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