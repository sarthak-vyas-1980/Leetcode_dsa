class Solution {
    bool solve(vector<vector<char>>& board, int row, int col, char val){
        for(int i=0; i<board.size(); i++){
            if(board[i][col]==val) return false;
            if(board[row][i]==val) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val) return false;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                char val = board[i][j];
                if(val!='.'){
                    board[i][j] = '.';
                    bool ans = solve(board, i, j, val);
                    if(!ans) return false;
                    board[i][j] = val;
                }
            }
        }
        return true;
    }
};