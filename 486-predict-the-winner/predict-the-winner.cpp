class Solution {
    int solve(vector<int>& piles, int s, int e, vector<vector<int>>& dp){
        if(s > e) return 0;
        if(dp[s][e] != -1) return dp[s][e];

        int start = piles[s] - solve(piles, s+1, e, dp);
        int end = piles[e] - solve(piles, s, e-1, dp);
        return dp[s][e] = max(start, end);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(nums, 0, nums.size()-1, dp) >= 0;
    }
};