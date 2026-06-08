class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxi = 0
        mini = prices[0]
        for i in prices:
            mini = min(mini, i)
            maxi = max(maxi, i - mini)
        return maxi