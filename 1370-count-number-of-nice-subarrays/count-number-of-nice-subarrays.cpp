class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int i = 0, count = 0, ans = 0;

        for(int j=0; j<nums.size(); j++){
            if(nums[j] & 1) count++;

            while(count > k){
                if(nums[i] & 1) count--;
                i++;
            }
            ans += j - i + 1;
        }   
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) { 
        return atMost(nums, k) - atMost(nums, k-1);
    }
};