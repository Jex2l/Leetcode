class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minvalue = prices[0]
        profit = 0
        for i in prices:
            minvalue = min(i, minvalue)
            profit = max(profit, i - minvalue)
        
        return profit
        