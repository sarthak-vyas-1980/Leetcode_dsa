class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans, diff = INT_MAX, n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int tar = nums[i] + nums[j] + nums[k];
                if(target == tar) return target; 
                if(abs(target - tar) < diff){
                    ans = tar;
                    diff = abs(target - tar);
                }
                if(target < tar) k--;
                else j++;
            }
            while(i+1 < nums.size()-2 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};