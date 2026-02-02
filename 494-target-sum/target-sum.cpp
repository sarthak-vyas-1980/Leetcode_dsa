class Solution {
    int solve(vector<int>& nums, int target, int sum, int index){
        if(index==-1 && sum==target) return 1;
        if(index==-1) return 0;

        int add = solve(nums, target, sum+nums[index], index-1);
        int sub = solve(nums, target, sum-nums[index], index-1);
        return add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, nums.size()-1);
        // vector<int> curr(nums.size()+1, 0);
        // vector<int> prev(nums.size()+1, 0);

        // prev[target]
        // for(int i=nums.size()-1; i>=0; i--){
        //     int sum = 0; 
        //     for8
        // }

    }
};