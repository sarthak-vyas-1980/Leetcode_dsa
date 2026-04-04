class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<unsigned int>> dp(coins.size()+1, vector<unsigned int>(amount + 1, 0));
        for(int i=0; i<=(int)coins.size(); i++){
            dp[i][0] = 1;
        }

        for(int i=coins.size()-1; i>=0; i--){
            for(int j=1; j<=amount; j++){
                unsigned int take = 0;
                if (j >= coins[i]) {
                    take = dp[i][j - coins[i]];
                }
                unsigned int skip = dp[i+1][j];;

                dp[i][j] = take + skip;
            }
        }
        return dp[0][amount];
    }
};


// class Solution {
// public:
//     int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
//         if (amount == 0) return 1;
//         if (i == coins.size()) return 0;
//         if (dp[i][amount] != -1) return dp[i][amount];

//         int take = 0;
//         if (coins[i] <= amount) {
//             take = solve(i, amount - coins[i], coins, dp);
//         }
//         int skip = solve(i + 1, amount, coins, dp);

//         return dp[i][amount] = take + skip;
//     }
//     int change(int amount, vector<int>& coins) {
//         vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
//         return solve(0, amount, coins, dp);
//     }
// };