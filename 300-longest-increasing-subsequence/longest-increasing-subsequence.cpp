class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return n;
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<n; i++){
            if(nums[i] > ans.back()) ans.push_back(nums[i]);
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
        // int n = nums.size();..........................................
        // vector<int> curr(n+1, 0);
        // vector<int> next(n+1, 0);

        // for(int i=n-1; i>=0; i--){
        //     for(int j=i-1; j>=-1; j--){
        //         int incl = 0;
        //         if(j == -1 || nums[i] > nums[j])
        //             incl = 1 + next[i+1];
        //         int excl = next[j+1];
        //         curr[j+1] = max(incl, excl);
        //     }
        //     next = curr;
        // }
        // return next[0];
    }
};