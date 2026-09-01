class Solution {
    bool solution(vector<int>& nums, int d, int t){
        int result = 0;
        for(int num: nums){
            if(num % d == 0) result += num/d;
            else result += (num/d) + 1;
        }
        return result <= t;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i = 1, j = INT_MIN;
        for(int num: nums) j = max(num, j);
        int mid = i + (j-i)/2, ans = j;

        while(i <= j){
            if(solution(nums, mid, threshold)){
                ans = mid;
                j = mid - 1;
            }
            else i = mid + 1;
            mid = i + (j-i)/2;
        }
        return ans;
    }
};