class Solution {
    bool isSafe(vector<vector<char>>& board, int row, int col, char val){
        for(int i=0; i<board.size(); i++){
            if(board[i][col]==val) return false;
            if(board[row][i]==val) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]=='.'){
                    for(char ch='1'; ch<='9'; ch++){
                        if(isSafe(board, i, j, ch)){
                            board[i][j] = ch;
                            bool sol = solve(board);
                            if(sol) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};