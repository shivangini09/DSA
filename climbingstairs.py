class Solution(object):
    def climbStairs(self, n):
        dp=[-1]*(n+1)     # initialising the array 
        dp[0]=1       #base cases
        dp[1]=1
        prev = dp[1]
        prev2 = dp[0]
        for i in range(2,n+1):
            dp[i] = prev + prev2     # total number of ways to reach on ith step
            prev2 = prev            
            prev = dp[i]
        return dp[n]
        
        
        