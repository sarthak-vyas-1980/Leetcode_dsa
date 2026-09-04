class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        vector<int> ans(nums.size());

        for(int num: nums){
            if(num >= 0){
                ans[pos] = num;
                pos += 2;
            }
            else{
                ans[neg] = num;
                neg += 2;
            }
        }
        return ans;
    }
};