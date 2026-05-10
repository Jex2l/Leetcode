class Solution {
public:
    int check(vector<vector<int>>& matrix, int& ans, int n, int m, int prev, vector<vector<int>>& dp) {
        if (n < 0 || m < 0 || n >= matrix.size() || m >= matrix[0].size()) return 0;
        if (matrix[n][m] <= prev) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        int maxi = 1;
        maxi = max(maxi, 1 + check(matrix, ans, n + 1, m, matrix[n][m], dp));
        maxi = max(maxi, 1 + check(matrix, ans, n - 1, m, matrix[n][m], dp));
        maxi = max(maxi, 1 + check(matrix, ans, n, m + 1, matrix[n][m], dp));
        maxi = max(maxi, 1 + check(matrix, ans, n, m - 1, matrix[n][m], dp));
        ans = max(ans, maxi);
        return dp[n][m] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) check(matrix, ans, i, j, -1, dp);
        }
        return ans;
    }
};