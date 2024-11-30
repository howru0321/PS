# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        iter_list = head
        pure_list=[]
        while iter_list!=None:
            val=iter_list.val
            pure_list.append(val)
            iter_list=iter_list.next
        
        n=len(pure_list)

        ans=0
        for i in range(n//2):
            left=pure_list[i]
            right=pure_list[n-i-1]

            twin_sum=left+right
            if ans<twin_sum:
                ans=twin_sum
        
        return ans
