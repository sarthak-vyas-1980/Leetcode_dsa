class Solution {
    int digitSum(int n){
        if(n<10) return n;
        int sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            ans = min(ans, digitSum(nums[i]));
        }
        return ans;
    }
};