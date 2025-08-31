class Solution {
    void solve(vector<vector<int>> &ans, vector<int>& nums,vector<int>& output ,vector<bool>& visited , int i){
        if(i>=nums.size()){
            ans.push_back(output);
            return;
        }
        for(int j=0; j<nums.size(); j++){
            // Skip duplicates: if current number is same as previous
            // and previous hasn't been used in this path, skip it
            if(j>0 && nums[j]==nums[j-1] && visited[j-1]==0) continue;
            if(!visited[j]){
                visited[j]=1;
                output.push_back(nums[j]);
                solve(ans, nums,output, visited, i+1);
                output.pop_back();   //back
                visited[j]=0;        //tracking
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;

        sort(nums.begin(), nums.end());// important for skipping duplicates
        vector<int> output;
        vector<bool> visited(nums.size(), 0);
        solve(ans, nums, output, visited, 0);
        return ans;
    }
};