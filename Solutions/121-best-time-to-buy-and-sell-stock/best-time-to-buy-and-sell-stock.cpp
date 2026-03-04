class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minnum = prices[0];
        int maxprice = 0;
        for(int i = 0; i<prices.size(); i++){
            minnum = min(minnum, prices[i]);
            maxprice = max(maxprice, prices[i] - minnum);
        }
        return maxprice;
    }
};