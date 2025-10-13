int solve2(vector<int> & cost, int n, vector<int> &dp){
    if(n == 0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
    return dp[n];
} 

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // int ans = min(solve(cost, n-1), solve(cost, n-2));
        // return ans;
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        return ans;
    }
};