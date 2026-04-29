class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
        if(index >= word.size()) return true;
        int rows = board.size();
            int cols = board[0].size();
            if(r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) return false;
            char t = board[r][c];
            board[r][c] = '#';
            bool found = dfs(board, word, r+1, c, index+1) ||
                        dfs(board, word, r-1, c, index+1) ||
                        dfs(board, word, r, c+1, index+1) ||
                        dfs(board, word, r, c-1, index+1);
                        
            board[r][c] = t;
            return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            if(dfs(board, word, r, c, 0)) return true;
        }
    }
    return false;
}
};

bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
    if(index >= word.size()) return true;
    int rows = board.size();
        int cols = board[0].size();
        if(r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) return false;
        char t = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, word, r+1, c, index+1) ||
                    dfs(board, word, r-1, c, index+1) ||
                    dfs(board, word, r, c+1, index+1) ||
                    dfs(board, word, r, c-1, index+1);
                    
        board[r][c] = t;
        return found;
}