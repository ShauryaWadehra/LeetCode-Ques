class Solution:
    def climbStairs(self, n: int) -> int:
        if n==0 or n==1:
            return 1
        prev = curr = 1
        for i in range(2,n+1):
            prev, curr = curr, prev + curr
        return curr