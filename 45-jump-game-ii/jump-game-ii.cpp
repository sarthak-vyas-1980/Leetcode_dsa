class Solution {
    int solveMem(vector<int>& nums, int index, vector<int>& dp){
        if(index == nums.size()-1) return 0;
        if(index >= nums.size()) return INT_MAX;
        if(dp[index] != -1) return dp[index];

        int ans = INT_MAX;
        for(int i=1; i<=nums[index]; i++){
            int jump = solveMem(nums, index+i, dp);
            if(jump != INT_MAX){
                ans = min(ans, jump + 1);
            }
        }
        dp[index] = ans;
        return ans;
    }
public:
    int jump(vector<int>& nums) {
        // vector<int> dp(nums.size()+1, - 1);
        // return solveMem(nums, 0, dp);

        vector<int> dp(nums.size(), INT_MAX);
        dp[nums.size()-1] = 0;

        for(int index=nums.size()-2; index>=0; index--){
            for(int i=1; i<=nums[index]; i++){
                if(i + index >= nums.size() || dp[index + i] == INT_MAX) continue;
                dp[index] = min(dp[index], dp[index + i] + 1);
            }
        }
        return dp[0];
    }
};