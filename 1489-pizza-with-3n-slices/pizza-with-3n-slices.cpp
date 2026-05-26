class Solution {
    int solve(vector<int>& slices, int n, int index, int endInd, vector<vector<int>>& dp){
        if(n == 0 || index > endInd) return 0;
        if(dp[index][n] != -1) return dp[index][n];

        int take = slices[index] + solve(slices, n-1, index + 2, endInd, dp);
        int notTake = 0 + solve(slices, n, index + 1, endInd, dp);
        return dp[index][n] = max(take, notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n+2, vector<int>(n+2, -1)), dp2(n+2, vector<int>(n+2, -1));
        return max(solve(slices, n/3, 0, n-2, dp1), solve(slices, n/3, 1, n-1, dp2));
    }
};