class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, ans = 0;

        while(j < nums.size()){
            if(mp[nums[j]] == k){
                for(int m=i; m<=j; m++){
                    if(nums[m] == nums[j]){
                        i = m + 1;
                        break;
                    }
                    else mp[nums[m]]--;
                }
            }
            else mp[nums[j]]++;

            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};