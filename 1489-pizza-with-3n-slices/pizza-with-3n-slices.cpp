class Solution {
    int solveMem(vector<int>& slices, int n, int index, int endInd, vector<vector<int>>& dp){
        if(n == 0 || index > endInd) return 0;
        if(dp[index][n] != -1) return dp[index][n];

        int take = slices[index] + solveMem(slices, n-1, index + 2, endInd, dp);
        int notTake = 0 + solveMem(slices, n, index + 1, endInd, dp);
        return dp[index][n] = max(take, notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        // int n = slices.size();
        // vector<vector<int>> dp1(n+2, vector<int>(n+2, -1)), dp2(n+2, vector<int>(n+2, -1));
        // return max(solveMem(slices, n/3, 0, n-2, dp1), solveMem(slices, n/3, 1, n-1, dp2));

        int n = slices.size();
        vector<int> prev1(n+2, 0), prev2(n+2, 0), curr1(n+2, 0), curr2(n+2, 0), next1(n+2, 0), next2(n+2, 0);

        for(int index=n-2; index>=0; index--){
            for(int k=1; k<=n/3; k++){
                int take = slices[index] + next1[k-1];
                int notTake = 0 + curr1[k];
                prev1[k] = max(take, notTake);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        for(int index=n-1; index>=1; index--){
            for(int k=1; k<=n/3; k++){
                int take = slices[index] + next2[k-1];
                int notTake = 0 + curr2[k];
                prev2[k] = max(take, notTake);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        return max(curr1[n/3], curr2[n/3]);
    }
};