class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int i, j;
        for(int one=0; one<(int)nums.size()-3; one++){
            for(int two=one+1; two<(int)nums.size()-2; two++){
                i = two + 1;
                j = nums.size()-1;
                long long tar = (long long)target - nums[one] - nums[two];

                while(i < j){
                    long long sum = (long long)nums[i] + nums[j];
                    if(sum == tar){
                        ans.push_back({nums[one], nums[two], nums[i++], nums[j--]});
                        while(i < j && nums[i] == nums[i-1]) i++;
                        while(j > i && nums[j] == nums[j+1]) j--;
                    }
                    else if(sum < tar) i++;
                    else j--;
                }
                while(two+1 < nums.size()-2 && nums[two] == nums[two+1]) two++;
            }
            while(one+1 < nums.size()-3 && nums[one] == nums[one+1]) one++;
        }
        return ans;
    }
};