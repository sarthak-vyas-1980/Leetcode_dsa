class Solution {
    void solve(vector<int>& nums, vector<int>& output, vector<vector<int>>&ans, int i ){
        if(i>=nums.size()){
            ans.push_back(output);
            return;
        }
        solve(nums, output, ans, i+1);

        output.push_back(nums[i]);
        solve(nums, output, ans, i+1);
        output.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;
        vector<int> output;
        solve(nums, output, ans, 0);
        return ans;
    }
};