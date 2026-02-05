class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return nums;
        vector<int> result(nums.size());
        for(int i=0; i<n; i++){
            int x = nums[i];
            if(x==0) result[i]=x;
            else if(x>0) result[i] = nums[(i+x)%(n)];
            else {
                int y = abs(x)%n;
                if((i-y)<0){
                    result[i] = nums[n+i-y];
                }
                else result[i] = nums[i-y];
            }
        }
        return result;
    }
};
