class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        all_dict=defaultdict(int)
        ans=0
        for num in nums:
            if all_dict[k-num]!=0:
                ans+=1
                all_dict[k-num]-=1
            else:
                all_dict[num]+=1

        return ans

