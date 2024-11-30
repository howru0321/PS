class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        prefix_sum={}

        total_sum=0
        for idx, num in enumerate(nums):
            total_sum+=num
            prefix_sum[idx]=total_sum

        for idx, num in enumerate(nums):
            left_sum=prefix_sum[idx]-num
            right_sum=total_sum-prefix_sum[idx]

            if left_sum==right_sum:
                return idx
        
        return -1