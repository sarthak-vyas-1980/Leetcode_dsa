class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, ans = 0;
        for(int num: nums){
            if(num == 0){
                ans = max(ans, count);
                count = 0;
            }
            else count++;
        }
        return max(ans, count);
    }
};