// class Solution {
// public:
//     int mins(vector<vector<int>>& grid, int row, int column, vector<vector<int>>& dp){
//         int rs = grid.size();
//         int cs = grid[0].size();
//         if(row >= rs || column >= cs) return INT_MAX;
//         if(row == rs - 1 && column == cs - 1) return grid[row][column];
//         if(dp[row][column] != -1) return dp[row][column];
//         int right = mins(grid, row, column + 1, dp);
//         int down  = mins(grid, row + 1, column, dp);
//         return dp[row][column] = grid[row][column] + min(right, down);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int rs = grid.size();
//         int cs = grid[0].size();
//         vector<vector<int>> dp(rs, vector<int>(cs, -1));
//         return mins(grid, 0, 0, dp);
//     }
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i == 0 && j == 0) continue;
                if(i == 0) grid[i][j] += grid[i][j-1];
                else if(j == 0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[r-1][c-1];
    }
};