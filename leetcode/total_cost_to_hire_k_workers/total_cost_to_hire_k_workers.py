class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        heap=[]
        heapq.heapify(heap)

        n=len(costs)
        left=min(candidates-1,n-2)
        right=max(left+1, n-candidates)

        for i in range(left+1):
            heapq.heappush(heap,(costs[i], i))
        for i in range(right,n):
            heapq.heappush(heap,(costs[i], i))
        
        total_cost=0
        for _ in range(k):
            min_cost, idx = heapq.heappop(heap)
            if(left<right):
                if idx<=left:
                    left+=1
                    if(left<right):
                        heapq.heappush(heap,(costs[left],left))
                elif idx>=right:
                    right-=1
                    if(left<right):
                        heapq.heappush(heap,(costs[right],right))
            total_cost+=min_cost
        
        return total_cost
