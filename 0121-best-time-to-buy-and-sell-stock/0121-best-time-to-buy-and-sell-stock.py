class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minprice = prices[0]
        maxprofit = 0
        for i in range(len(prices)):
            minprice = min(minprice,prices[i])
            maxprofit = max(maxprofit, prices[i]-minprice)
        return maxprofit