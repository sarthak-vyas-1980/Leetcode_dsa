class Solution {
    long long solve(int index, int opr, bool isShort, vector<int>& prices, int k, vector<vector<vector<long long>>>& dp){
        if(index == prices.size()){
            if(opr % 2 == 0) return 0;   // no open position
            return -1e15;                // open position left
        }
        if(opr == 2*k) return 0;
        if(dp[index][opr][isShort] != -1) return dp[index][opr][isShort];
        
        long long profit = 0;
        if(opr%2 == 0) {  //buy and sell both allowed
            long long buyKaro = -prices[index] + solve(index+1, opr+1, 0, prices, k, dp);
            long long skipKaro = 0 + solve(index+1, opr, 0, prices, k, dp);
            long long sellKaro = prices[index] + solve(index+1, opr+1, 1, prices, k, dp);
            profit = max(buyKaro, max(skipKaro, sellKaro));
        }
        else {
            if(isShort == 0){
                long long sellKaro = prices[index] + solve(index+1, opr+1, 0, prices, k, dp);
                long long skipKaro = 0 + solve(index+1, opr, 0, prices, k, dp);
                profit = max(sellKaro, skipKaro);
            }
            else{
                long long buyKaro = -prices[index] + solve(index+1, opr+1, 1, prices, k, dp);
                long long skipKaro = 0 + solve(index+1, opr, 1, prices, k, dp);
                profit = max(buyKaro, skipKaro);
            }
        }
        return dp[index][opr][isShort] = profit;
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        // int n = prices.size();
        // vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2*k+1, vector<long long>(2, -1)));
        // return solve(0, 0, 0, prices, k, dp);
        
        int n = prices.size();
        // vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2*k+1, vector<long long>(2, 0)));
        vector<vector<long long>> curr(2*k+1, vector<long long>(2, 0));
        vector<vector<long long>> next(2*k+1, vector<long long>(2, 0));
        for(int o=0; o<=2*k; o++){
            if(o%2 == 1) next[o][0] = next[o][1] = -1e15;
        }

        for(int index=n-1; index>=0; index--){
            for(int opr=2*k-1; opr>=0; opr--){
                for(int isShort=1; isShort>=0; isShort--){
                    long long profit = 0;
                    if(opr%2 == 0) {  //buy and sell both allowed
                        long long buyKaro = -prices[index] + next[opr+1][0];
                        long long skipKaro = 0 + next[opr][0];
                        long long sellKaro = prices[index] + next[opr+1][1];
                        profit = max(buyKaro, max(skipKaro, sellKaro));
                    }
                    else {
                        if(isShort == 0){
                            long long sellKaro = prices[index] + next[opr+1][0];
                            long long skipKaro = 0 + next[opr][0];
                            profit = max(sellKaro, skipKaro);
                        }
                        else{
                            long long buyKaro = -prices[index] + next[opr+1][1];
                            long long skipKaro = 0 + next[opr][1];
                            profit = max(buyKaro, skipKaro);
                        }
                    }
                    curr[opr][isShort] = profit;
                }
            }
            next = curr;
        }
        return next[0][0];
    }
};