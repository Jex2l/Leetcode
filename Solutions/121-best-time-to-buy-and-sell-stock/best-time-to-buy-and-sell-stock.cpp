class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Babbar Solution
        int mini = prices[0];
        int profit = 0;
        for(int i = 1; i< prices.size(); i++){
            int diff = prices[i] - mini;
            profit = max(profit, diff);
            mini = min(mini, prices[i]);
        }
        return profit;

        // Leetcode Solution
        // int l = 0, r = 1;
        // int maxP = 0;

        // while (r < prices.size()) {
        //     if (prices[l] < prices[r]) {
        //         int profit = prices[r] - prices[l];
        //         maxP = max(maxP, profit);
        //     } else {
        //         l = r;
        //     }
        //     r++;
        // }
        // return maxP;

        // My Solution(Brut Force)
        // if(prices.size() == 2){
        //     if((prices[1] - prices[0]) < 0){
        //         return 0;
        //     }
        //     return prices[1] - prices[0];
        // }

        // vector<int> arr;
        // for(int i = 0; i<prices.size(); i++){
        //     for(int j = i; j< prices.size(); j++){
        //         arr.push_back(prices[j] - prices[i]);
        //     }
        // }
        // int ans = 0;
        // for(int i = 0; i<arr.size(); i++){
        //     if(arr[i] > ans){
        //         ans = arr[i];
        //     }
        // }
        // return ans;
    }
};