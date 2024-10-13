#include <cmath>

class Solution {
public:
  double diff = 2e9;
  int target_value = -1;
  const double epsilon = 1e-6;
  bool isEqual(double a, double b, double epsilon) {
    // cout<<abs(a-b)<<" "<<a<<" "<<b<<endl;
    // cout<<bool(fabs(a-b)<epsilon)<<endl;
    return fabs(a - b) < epsilon;
  }
  int closestValue(TreeNode *root, double target) {
    if (root == nullptr) {
      return target_value;
    }

    double current_diff = fabs(root->val - target);
    // cout<<current_diff<<endl;
    if (current_diff < diff)
      diff = current_diff, target_value = root->val;
    if (isEqual(current_diff, diff, epsilon)) {
      if (target_value > root->val) {
        target_value = root->val;
      }
    }

    if (root->left != nullptr and target < root->val) {
      root = root->left;
      closestValue(root, target);
    }
    if (root->right != nullptr and target > root->val) {
      root = root->right;
      closestValue(root, target);
    }
    // return -1;
    return target_value;
  }
};