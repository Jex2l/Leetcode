int solve(int n, vector<int> &dp){
    if(n == 0) return 0;
    int ans = n;
    if(dp[n] != -1){
        return dp[n];
    }

    for(int i = 1; i*i <= n; i++){
        int temp = i*i;
        ans = min(ans, 1+solve(n-temp, dp));
    }
    dp[n] = ans;
    return dp[n];
}
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};