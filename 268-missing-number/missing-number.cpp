class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int arrSum = 0;
        for(int i=0; i<n; i++){
            arrSum += nums[i];
        }
        return sum - arrSum;
    }
    // int missingNumber(vector<int>& nums) {..............................
    //     int ans = 0;
    //     int n = nums.size();
    //     for(int i=0; i<=n; i++){
    //         ans ^= i;
    //     }
    //     for(int i:nums) ans ^= i;
    //     return ans;
    // }
    // int missingNumber(vector<int>& nums) {...............................
    //     int n = nums.size() + 1;
    //     nums.push_back(1000000);
    //     for(int i=0; i<n-1; i++){
    //         nums[abs(nums[i])] *= -1;
    //     }
    //     for(int i=0; i<n; i++){
    //         if(nums[i]>0) return i; 
    //     }
    //     return n;
    // }
};