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
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, 0, 0, dp);
    }
};