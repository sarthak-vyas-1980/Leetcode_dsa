class Solution {
    void solve(vector<vector<int>> &ans, vector<int>& nums, int i){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i; j<nums.size(); j++){
            swap(nums[i],nums[j]);
            solve(ans, nums, i+1);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;
        solve(ans, nums, 0);
        return ans;
    }
};