class Solution {
    void solve(vector<int>& nums, vector<int>& output, vector<vector<int>>&ans, int i ){
        if(i>=nums.size()){
            ans.push_back(output);
            return;
        }
        output.push_back(nums[i]);//included
        solve(nums, output, ans, i+1);
        output.pop_back();

        int idx = i+1;//excluded
        while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        solve(nums, output, ans, idx);
    }                                      
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;
        sort(nums.begin(),nums.end());
        vector<int> output;
        solve(nums, output, ans, 0);
        return ans;
    }
};