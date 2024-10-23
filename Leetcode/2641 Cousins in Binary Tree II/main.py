from collections import deque
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return root;
        node_queue=deque()
        node_queue.append(root)
        previous_level_sum=root.val
        while node_queue:
            level_size=len(node_queue)
            current_level_sum=0
            for _ in range(level_size):
                current_node=node_queue.popleft()
                current_node.val=previous_level_sum-current_node.val
                sibling_sum=(current_node.left.val if current_node.left else 0)+(current_node.right.val if current_node.right else 0)
                if(current_node.left):
                    node_queue.append(current_node.left)
                    current_level_sum+=current_node.left.val
                    current_node.left.val=sibling_sum
                if(current_node.right):
                    node_queue.append(current_node.right)
                    current_level_sum+=current_node.right.val
                    current_node.right.val=sibling_sum
            previous_level_sum=current_level_sum

        return root;
        
        