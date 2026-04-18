class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p = n-1;
        while(p>0){
            if(nums[p-1] < nums[p] && p==n-1){
                swap(nums[p-1], nums[p]);
                return ;
            }
            if(nums[p-1] < nums[p]) break;
            p--;
        }   
        if(p==0) reverse(nums.begin(), nums.end());
        else{
            int index = p-1;
            for(int i=p; i<n; i++){
                if(nums[p-1] < nums[i] && (index == p-1 || nums[index] >= nums[i])) index = i;
            }
            swap(nums[index], nums[p-1]);
            sort(nums.begin()+p, nums.end());
        }
    }
};