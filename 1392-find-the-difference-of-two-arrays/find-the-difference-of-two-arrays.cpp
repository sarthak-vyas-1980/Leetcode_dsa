class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num1(nums1.begin(), nums1.end());
        unordered_set<int> num2(nums2.begin(), nums2.end());
        vector<vector<int>> ans;

        vector<int> temp;
        for(int num: num1){
            if(!num2.count(num)) temp.push_back(num);
        }
        ans.push_back(temp);
        temp.clear();
        for(int num: num2){
            if(!num1.count(num)) temp.push_back(num);
        }
        ans.push_back(temp);
        return ans;
    }
};