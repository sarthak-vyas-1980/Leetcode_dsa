class Solution {
    int solve(vector<int>& prices, int index, int buy, vector<vector<int>>& dp){
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];

        int ans = 0;
        if(buy){
            int buyIt = -prices[index] + solve(prices, index+1, 0, dp);
            int ignore = solve(prices, index+1, 1, dp);
            ans = max(buyIt, ignore);
        }
        else{
            int sellIt = +prices[index] + solve(prices, index+2, 1, dp);
            int ignore = solve(prices, index+1, 0, dp);
            ans = max(sellIt, ignore);
        }
        return dp[index][buy] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};