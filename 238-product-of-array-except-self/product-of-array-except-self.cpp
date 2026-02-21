class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int suffix = 1;
        for(int j=n-2; j>=0; j--){
            suffix *= nums[j+1];
            ans[j] = ans[j] * suffix;
        }
        return ans;
    }
    // vector<int> productExceptSelf(vector<int>& nums) {.........
    //     int n = nums.size();
    //     vector<int> prefix(n);
    //     vector<int> suffix(n);

    //     for(int i=0; i<n; i++){
    //         if(i==0){
    //             prefix[i] = 1;
    //             suffix[n-i-1] = 1;
    //         }
    //         else{
    //             prefix[i] = prefix[i-1] * nums[i-1];
    //             suffix[n-i-1] = suffix[n-i] * nums[n-i];
    //         }
    //     }
    //     for(int i=0; i<n; i++){
    //         nums[i] = prefix[i] * suffix[i];
    //     }
    //     return nums;
    // }
};