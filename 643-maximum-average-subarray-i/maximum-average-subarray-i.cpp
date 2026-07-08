class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        double ans;

        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        ans = sum/(double)k;

        for(int i=k; i<nums.size(); i++){
            sum -= nums[i-k];
            sum += nums[i];
            if(ans < sum/(double)k) ans = sum/(double)k;
        }
        return ans;
    }
};