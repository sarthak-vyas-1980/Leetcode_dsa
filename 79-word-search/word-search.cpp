class Solution {
    bool isSafe(int x,int y,vector<vector<char>>& board,vector<vector<bool>>&visited,int i,string& word,int m,int n){
        if(word.length()==i) return true;
        if(x<0 || x>=m || y<0 || y>=n) return false;
        if(board[x][y] != word[i] || visited[x][y]==1) return false;
        return true;
    }
    bool solve(int x,int y,int i,vector<vector<char>>& board,vector<vector<bool>>& visited,string& word,int m,int n){
        if(i==word.length()) return true;
        visited[x][y]=1;

        int arr[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for(int p=0; p<4; p++){
            if(isSafe(x+arr[p][0], y+arr[p][1], board, visited, i+1, word, m, n)){
                bool temp = solve(x+arr[p][0], y+arr[p][1], i+1, board, visited, word, m, n);
                if(temp) return true;
            }
        }
        
        visited[x][y]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(m==0 && n==0)return false;
        vector<vector<bool>> visited(m, vector<bool>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0] && solve(i, j, 0, board, visited, word, m, n)) return true;
            }
        }
        return false;
    }
};