class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int j=1; j<=amount; j++){
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++){
                if(j-coins[i]>=0 && dp[j-coins[i]]!=INT_MAX) mini = min(mini, 1 + dp[j-coins[i]]);
            }
            dp[j] = mini;
        }
        return dp[amount] == INT_MAX ? -1: dp[amount];
    }
};

// class Solution {
//     int solve(vector<int>& coins, int sum, vector<int>& dp) {
//         if(sum == 0) return 0;
//         if(sum < 0) return INT_MAX;
//         if(dp[sum] != -1) return dp[sum];
        
        // int mini = INT_MAX;
        // for(int i=0; i<coins.size(); i++){
        //     int ans = solve(coins, sum - coins[i], dp);
        //     if(ans != INT_MAX) mini = min(mini, 1 + ans);
        // }
//         dp[sum] = mini;
//         return mini;
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount == 0) return 0;
//         vector<int> dp(amount + 1, -1);
//         int ans = solve(coins, amount, dp);
//         return ans == INT_MAX? -1 : ans;
//     }
// };