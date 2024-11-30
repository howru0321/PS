# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def DFS(self, node: Optional[TreeNode], isleft: bool):
        if node==None:
            return 0, 0

        left_connect, left_max=self.DFS(node.left, True)
        right_connect, right_max=self.DFS(node.right, False)

        if isleft:
            connect = right_connect + 1
            max_val = max(left_connect, left_max, right_max)
        else:
            connect = left_connect + 1
            max_val = max(left_max, right_connect, right_max)
        
        return connect, max_val


    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        left_connect, left_max=self.DFS(root.left, True)
        right_connect, right_max=self.DFS(root.right, False)

        return max(left_connect, right_connect, left_max, right_max)