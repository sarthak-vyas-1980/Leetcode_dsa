class Solution {
    int solve(vector<int>& piles, int s, int e, vector<vector<int>>& dp){
        if(s > e) return 0;
        if(dp[s][e] != -1) return dp[s][e];

        int ans = 0;
        if((e - s) & 1){
            int start = piles[s] + solve(piles, s+1, e, dp);
            int end = piles[e] + solve(piles, s, e-1, dp);
            ans = max(start, end);
        }

        else{
            int start = -piles[s] + solve(piles, s+1, e, dp);
            int end = -piles[e] + solve(piles, s, e-1, dp);
            ans = max(start, end);
        }
        return dp[s][e] = ans;
    }
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));
        return solve(piles, 0, piles.size()-1, dp) > 0;
    }
};