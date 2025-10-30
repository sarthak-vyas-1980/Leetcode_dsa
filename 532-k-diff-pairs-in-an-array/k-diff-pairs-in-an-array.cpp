class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        int i = 0;
        while(i<nums.size()){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]-nums[j]==k || nums[j]-nums[i]==k){
                    ans++;
                    break;
                }
            }
            int j=i+1;
            while(j<nums.size() && nums[j]==nums[i]) j++;
            i=j;
        }
        return ans;
    }
};