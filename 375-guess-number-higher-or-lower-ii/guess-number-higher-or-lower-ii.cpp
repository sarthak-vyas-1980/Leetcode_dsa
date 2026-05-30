class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--){
            for(int j=i; j<=n; j++){
                if(i==j) continue;
                int ans = INT_MAX;
                for(int k=i; k<=j; k++){
                    ans = min(ans, k+ max(dp[i][k-1], dp[k+1][j]));
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};