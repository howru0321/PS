class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left=0
        num_zeros=0
        ans=0
        for idx, num in enumerate(nums):
            if num==0:
                num_zeros+=1
            while num_zeros>k:
                if nums[left]==0:
                    num_zeros-=1
                left+=1
            
            length=idx-left+1

            if ans<length:
                ans=length
        
        return ans