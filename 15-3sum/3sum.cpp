class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n == 0) return ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int target = -nums[i];
            int j=i+1, k=n-1;
            while(j<k){
                int sum = nums[j] + nums[k]; 
                if(sum == target){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    k--;
                    while(k>j && nums[k] == nums[k+1]) k--;
                }
                else if(sum > target) k--;
                else j++;
            }
            while(i+1<n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     unordered_map<int, int> mp;
    //     for(int i=0; i<nums.size(); i++){
    //         mp[nums[i]] = i;
    //     }
    //     vector<vector<int>> ans;
    //     for(int i=0; i<nums.size(); i++){
    //         for(int j=i+1; j<nums.size(); j++){
    //             int term = -(nums[i]+nums[j]);
    //             if(mp.count(term) && mp[term]>j){
    //                 vector<int> path;
    //                 ans.push_back({nums[i], nums[j], term}); 
    //             }
    //         }
    //         while(i+1<nums.size() && nums[i+1]==nums[i]) i++; 
    //     }
    //     return ans;
    // }
};