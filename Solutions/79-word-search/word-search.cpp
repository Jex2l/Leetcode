class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int index, int x, int y){
        if(index == word.size()) return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[index]) return false;
        char temp = board[x][y];
        board[x][y] = '#';
        bool found = dfs(board, word, index + 1, x+1, y) ||
                     dfs(board, word, index + 1, x-1, y) ||
                     dfs(board, word, index + 1, x, y+1) ||
                     dfs(board, word, index + 1, x, y-1);
        board[x][y] = temp;
        return found;
    }
};