class Solution {
    bool isPossible(vector<int>&nums, int k, int sum){
        int curr = 0;
        for(int num: nums){
            if(curr + num <= sum) curr += num;
            else{
                curr = num;
                k--;
                if(k == 0) return false;
            }
        }
        return k >= 1;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low < high){
            int mid = low + (high - low)/2;
            if(isPossible(nums, k, mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};