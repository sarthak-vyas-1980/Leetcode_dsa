// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
        
//         int ans = 0;
//         int i = 0;
//         while(i<nums.size()){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[i]-nums[j]==k || nums[j]-nums[i]==k){
//                     ans++;
//                     break;
//                 }
//             }
//             int j=i+1;
//             while(j<nums.size() && nums[j]==nums[i]) j++;
//             i=j;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> count1;
        for(int i=0; i<nums.size(); i++){
            count1[nums[i]]++;
        }
        int ans = 0;
        for(auto i: count1){
            if(k==0){
                if(i.second>1) ans++;
            } else {
                if(count1.count(i.first+k)) ans++;
            }
        }
        return ans;
    }
};