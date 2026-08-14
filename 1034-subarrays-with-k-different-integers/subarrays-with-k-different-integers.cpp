class Solution {
    int atMostK(vector<int>& nums, int k){
        int n = nums.size(), ans = 0;
        int left = 0, right = 0;
        unordered_map<int, int> freq;

        while (right < n) {
            freq[nums[right]]++;
            if (freq[nums[right]] == 1) k--;

            while (k < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) k++;
                left++;
            }

            ans += (right - left + 1);
            right++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
};
