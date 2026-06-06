class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);

        for(int index=n-1; index>=0; index -- ) {
            for(int operationNo=0; operationNo<2*k; operationNo++) {
                int profit = 0;
                if(operationNo%2 == 0) {  //buy allowed
                    int buyKaro = -prices[index] + next[operationNo+1];
                    int skipKaro = 0 + next[operationNo];
                    profit = max( buyKaro, skipKaro );
                }
                else {
                    int sellKaro = prices[index] + next[operationNo+1];
                    int skipKaro = 0 + next[operationNo];
                    profit = max(sellKaro, skipKaro);
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
    return next[0];

        // int n = prices.size();
        // vector<vector<int>> curr(2, vector<int>(k+1, 0));
        // vector<vector<int>> next(2, vector<int>(k+1, 0));

        // for(int index=n-1; index>=0; index--){
        //     for(int buy=0; buy<=1; buy++){
        //         for(int limit=1; limit<=k; limit++){
        //             if(buy){
        //                 int buyStock = -prices[index] + next[0][limit];
        //                 int skip = next[1][limit];
        //                 curr[buy][limit] = max(buyStock, skip);
        //             }else{
        //                 int sell = prices[index] + next[1][limit-1];
        //                 int skip = next[0][limit];
        //                 curr[buy][limit] = max(sell, skip);
        //             }
        //         }
        //     }
        //     next = curr;
        // }
        // return next[1][k];
    }
};