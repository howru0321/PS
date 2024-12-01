class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        k_min=1
        k_max=max(piles)
        while k_min<=k_max:
            mid=(k_min+k_max)//2

            total_hour=0
            for pile in piles:
                total_hour+=pile//mid
                if pile%mid!=0:
                    total_hour+=1
            
            if total_hour<=h:
                ans=mid
                k_max=mid-1
            elif total_hour>h:
                k_min=mid+1

        return ans
        