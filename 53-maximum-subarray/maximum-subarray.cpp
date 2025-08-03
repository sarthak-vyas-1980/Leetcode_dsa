#include<math.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    //     long long maxSum = LLONG_MIN;             ...Brute Force...
    //     for(int i=0; i<nums.size(); i++){
    //         long long sum=0;
    //         for(int j=i; j<nums.size(); j++){
    //             sum += nums[j];
    //             maxSum = max(sum, maxSum);
    //         }
    //     }
    //     return (int)maxSum;
    // }
        long long maxSum = LONG_MIN, sum=0;  
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxSum= max(maxSum, sum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
};