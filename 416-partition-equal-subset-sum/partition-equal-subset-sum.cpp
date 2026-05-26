class Solution {
    bool solveMem(vector<int>& nums, int& sum, int index, int val, vector<vector<int>>& dp){
        if(index >= nums.size() && sum/2 == val) return true;
        if(index >= nums.size() && sum/2 != val) return false;
        if(dp[index][val] != -1) return dp[index][val];

        bool take = solveMem(nums, sum, index+1, val + nums[index], dp); 
        bool notTake = solveMem(nums, sum, index+1, val, dp); 
        return dp[index][val] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) sum += num;
        if(sum%2 == 1) return false;

        // vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, -1));
        // return solveMem(nums, sum, 0, 0, dp);

        vector<int> curr((sum/2)+1, 0);
        vector<int> next((sum/2)+1, 0);
        next[0] = 1;

        for(int index=nums.size()-1; index>=0; index--){
            for(int val=1; val<=sum/2; val++){ 
                bool take = 0;
                if(val-nums[index]>=0) take = next[val-nums[index]];
                bool notTake = next[val];
                curr[val] = take || notTake;
            }
            next = curr;
        }
        return curr[sum/2];
    }
};