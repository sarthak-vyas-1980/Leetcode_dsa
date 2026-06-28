class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int i = -1, j = nums.size();

        for(int k=0; k<nums.size(); k++){
            if(nums[k] >= 0){
                j = k;
                break;
            }
            else i = k;
        }

        while(i >= 0 && j < nums.size()){
            if(nums[i]*nums[i] <= nums[j]*nums[j]){
                ans.push_back(nums[i] * nums[i--]);
            }
            else{
                ans.push_back(nums[j] * nums[j++]);
            }
        }
        while(i >= 0) ans.push_back(nums[i] * nums[i--]);
        while(j < nums.size()) ans.push_back(nums[j] * nums[j++]);

        return ans;
    }
};