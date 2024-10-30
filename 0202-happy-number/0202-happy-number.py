class Solution:
    def isHappy(self, n: int) -> bool:
        slow,fast = n,self.sumsquare(n)
        while slow!=fast:
            slow = self.sumsquare(slow)
            fast = self.sumsquare(fast)
            fast = self.sumsquare(fast)
        return True if fast == 1 else False
    
    def sumsquare(self, n : int) -> int:
        new = 0
        while n:
            new = new + (n%10)**2
            n = n//10
        return new