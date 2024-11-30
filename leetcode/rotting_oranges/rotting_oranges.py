class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        stack = deque()
        n=len(grid)
        m=len(grid[0])

        for i in range(n):
            for j in range(m):
                orange=grid[i][j]
                if orange==2:
                    stack.append((i,j))
        
        ans=0
        while stack:
            rotten_oranges=[]

            while stack:
                rotten_oranges.append(stack.pop())

            ischanged=False
            for rotten_orange in rotten_oranges:
                x, y=rotten_orange
                if x>0:
                    if grid[x-1][y]==1:
                        ischanged=True
                        grid[x-1][y]=2
                        stack.append((x-1,y))
                if x<n-1:
                    if grid[x+1][y]==1:
                        ischanged=True
                        grid[x+1][y]=2
                        stack.append((x+1,y))
                if y>0:
                    if grid[x][y-1]==1:
                        ischanged=True
                        grid[x][y-1]=2
                        stack.append((x,y-1))
                if y<m-1:
                    if grid[x][y+1]==1:
                        ischanged=True
                        grid[x][y+1]=2
                        stack.append((x,y+1))
            
            if ischanged:
                ans+=1
        
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1:
                    return -1
        
        return ans
