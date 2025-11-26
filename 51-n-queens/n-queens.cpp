#include<unordered_map>
class Solution {
    void calc(vector<vector<int>>& board, vector<vector<string>>& ans, int n){
        vector<string> temp;
        for(int i=0; i<n; i++){
            string tempAns;
            for(int j=0; j<n; j++){
                if(board[i][j]==1) tempAns.push_back('Q');
                else tempAns.push_back('.');
            }
            temp.push_back(tempAns);
        }
        ans.push_back(temp);
    }
    bool isSafe(vector<vector<int>>& board,int row,int col,int n){
        int x=row;
        int y=col;
        while(y>=0){
            if(board[x][y]==1)
                return false;
            y--;
        }
        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]==1)
                return false;
            y--;
            x--;
            
        }
        x=row;
        y=col;
        while(x<n && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void traversal(int col, vector<vector<int>>& board, int n, vector<vector<string>>& ans){
        if(col==n){
            calc(board, ans, n);
            return; 
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]=1;
                traversal(col+1,board,n,ans);
                board[row][col]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<string>> ans;
        traversal(0,board,n,ans);
        return ans;
    }
};