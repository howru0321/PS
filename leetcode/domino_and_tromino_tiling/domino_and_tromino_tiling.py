class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 10**9 + 7
        
        if n == 0:
            return 1
        elif n == 1:
            return 1
        elif n == 2:
            return 2
        
        dp = [0] * (n + 1)
        dp2 = [0] * (n + 1)
        
        dp[0]=1
        dp[1]=1
        dp[2]=2

        dp2[0]=0
        dp2[1]=2
        dp2[2]=2

        for i in range(3,n+1):
            dp[i] = (dp[i-1] * 1 + dp[i-2] * 1 + dp2[i-1] * 1) % MOD
            dp2[i] = (dp2[i-1] * 1 + dp[i-2] * 2) % MOD
        
        return dp[n]
