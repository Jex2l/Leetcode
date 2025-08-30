class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<int> x(10, 0);
            for(int j = 0; j < 9; j++){
                
                if(board[i][j]=='.')
                    continue;
                else if(x[board[i][j]-'0'] == 0){
                    x[board[i][j]-'0'] = 1;
                }else{
                    return false;
                }
            }
        }
        for(int i = 0; i < 9; i++){
            vector<int> x(10, 0);
            for(int j = 0; j < 9; j++){
                cout<<board[j][i];
                if(board[j][i]=='.')
                    continue;
                else if(x[board[j][i]-'0'] == 0){
                    x[board[j][i]-'0'] = 1;
                }else{
                    return false;
                }
            }
        }
        for(int m = 0; m < 9; m=m+3){
            for(int n = 0; n < 9; n=n+3){
                vector<int> x(10, 0);
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[i+ m][j+n]=='.')
                            continue;
                        else if(x[board[i+ m][j+n]-'0'] == 0){
                            x[board[i+m][j+n]-'0'] = 1;
                        }else{
                            return false;
                        }       
                    }
                }
            }
        }
        return true;
    }
};