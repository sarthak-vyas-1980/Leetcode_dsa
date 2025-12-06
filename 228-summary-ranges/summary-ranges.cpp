#include<string>
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i=0;
        while(i<nums.size()){
            int j=i+1;
            while(j<nums.size() && nums[j]==nums[j-1]+1) j++;
            if(j==i+1) ans.push_back(std::to_string(nums[i++]));
            else {
                j--;
                string s = std::to_string(nums[i]);
                s += "->";
                s += std::to_string(nums[j]);
                ans.push_back(s);
                i=j+1;
            }
        }
        return ans;
    }
};