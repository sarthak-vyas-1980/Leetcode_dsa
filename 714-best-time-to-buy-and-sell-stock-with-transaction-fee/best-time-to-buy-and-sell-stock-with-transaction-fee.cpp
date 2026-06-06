class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                if(buy){
                    int buyStock = -prices[index] + next[0];
                    int skip = next[1];
                    curr[buy] = max(buyStock, skip);
                } else {
                    int sell = prices[index] + next[1] - fee;
                    int skip = next[0];
                    curr[buy] = max(sell, skip);
                }
            }
            next = curr;
        }
        return next[1];
    }
};