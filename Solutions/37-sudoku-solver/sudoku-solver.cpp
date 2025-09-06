static vector<vector<int>> toIntGrid(const vector<vector<char>>& board) {
    const int n = (int)board.size();
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)board[i].size(); ++j) {
            char c = board[i][j];
            g[i][j] = (c == '.') ? 0 : (c - '0');  // safe since inputs are '1'..'9' or '.'
        }
    }
    return g;
}

// Convert int grid -> char board (0 -> '.', 1..9 -> '1'..'9')
static void fromIntGrid(const vector<vector<int>>& g, vector<vector<char>>& board) {
    const int n = (int)g.size();
    board.assign(n, vector<char>(n, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)g[i].size(); ++j) {
            int v = g[i][j];
            board[i][j] = (v == 0) ? '.' : char('0' + v);
        }
    }
}

bool isSafe(int row, int col, vector<vector<int>> &grid, int val){
    int n = grid[0].size();
    for(int i = 0; i<n; i++){
        if(grid[row][i] == val){
            return false;
        }
        if(grid[i][col] == val){
            return false;
        }
        if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }
    return true;
}


bool solve(vector<vector<int>> &grid){
    int n = grid[0].size();
    for(int row = 0; row<n; row++){
        for(int col = 0; col < n; col++){
            if(grid[row][col] == 0){
                for(int val = 1; val<=9; val++){
                    if(isSafe(row, col, grid, val)){
                        grid[row][col] = val;
                        bool nextSolution = solve(grid);
                        if(nextSolution){
                            return true;
                        }
                        else{
                            grid[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> grid = toIntGrid(board);
        solve(grid);

    // 2) Convert back to the required char format.
        fromIntGrid(grid, board);
    }
};