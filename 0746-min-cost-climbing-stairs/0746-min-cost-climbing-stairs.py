class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = 0
        dp1 = dp2 = 0
        for i in range(2,n+1):
            dp = min(cost[i-1]+ dp1, cost[i-2]+dp2)
            dp1,dp2 = dp, dp1
        return dp