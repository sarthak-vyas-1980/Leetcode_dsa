class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=2; limit++){
                    if(buy){
                        int buyStock = -prices[index] + next[0][limit];
                        int skip = next[1][limit];
                        curr[buy][limit] = max(buyStock, skip);
                    }else{
                        int sell = prices[index] + next[1][limit-1];
                        int skip = next[0][limit];
                        curr[buy][limit] = max(sell, skip);
                    }
                }
            }
            next = curr;
        }
        return next[1][2];
    }
};