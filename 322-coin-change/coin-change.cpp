class Solution {
    int solve(vector<int>& coins, int sum, vector<int>& dp) {
        if(sum == 0) return 0;
        if(sum < 0) return INT_MAX;
        if(dp[sum] != -1) return dp[sum];
        
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solve(coins, sum - coins[i], dp);
            if(ans != INT_MAX) mini = min(mini, 1 + ans);
        }
        dp[sum] = mini;
        return mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        return ans == INT_MAX? -1 : ans;
    }
};