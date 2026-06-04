class Solution {
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int n = grid.size(), m = grid[0].size();
        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int right = INT_MAX, down = INT_MAX;
        if(i+1 < n) down = grid[i][j] + solve(grid, i+1, j, dp);
        if(j+1 < m) right = grid[i][j] + solve(grid, i, j+1, dp);
        return dp[i][j] = min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // return solve(grid, 0, 0, dp);

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[n-1][m-1] = grid[n-1][m-1];

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1) continue;
                int right = INT_MAX, down = INT_MAX;
                if(i+1 < n) down = grid[i][j] + dp[i+1][j];
                if(j+1 < m) right = grid[i][j] + dp[i][j+1];
                dp[i][j] = min(right, down);
            }
        }
        return dp[0][0];
    }
};