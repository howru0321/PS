# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:

        queue = deque()

        queue.append(root)
        max_sum=-100001
        max_level=10001
        level=1
        while queue:
            same_level=[]
            while queue:
                same_level.append(queue.popleft())
            
            level_sum=0
            for node in same_level:
                val=node.val
                level_sum+=val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            if max_sum<level_sum:
                max_sum=level_sum
                max_level=level
                
            level+=1
            
        return max_level