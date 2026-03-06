class Solution {
public:
    int mins(vector<vector<int>>& grid, int row, int column, vector<vector<int>>& dp){
        int rs = grid.size();
        int cs = grid[0].size();
        if(row >= rs || column >= cs) return INT_MAX;
        if(row == rs - 1 && column == cs - 1) return grid[row][column];
        if(dp[row][column] != -1) return dp[row][column];
        int right = mins(grid, row, column + 1, dp);
        int down  = mins(grid, row + 1, column, dp);
        return dp[row][column] = grid[row][column] + min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();
        vector<vector<int>> dp(rs, vector<int>(cs, -1));
        return mins(grid, 0, 0, dp);
    }
};