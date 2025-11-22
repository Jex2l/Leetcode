class Solution {
public:
    static const int MOD = 1e9 + 7;
    int solve(int dice, int faces, int target, vector<vector<int>> &dp) {
        if (target < 0) return 0;
        if (dice == 0) return (target == 0) ? 1 : 0;
        if (dp[dice][target] != -1) {
            return dp[dice][target];
        }
        long long ans = 0;
        for (int face = 1; face <= faces && target - face >= 0; face++) {
            ans += solve(dice - 1, faces, target - face, dp);
            if (ans >= MOD) ans -= MOD;
        }

        dp[dice][target] = (int)(ans % MOD);
        return dp[dice][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};
