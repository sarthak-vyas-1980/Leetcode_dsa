class Solution {
    void reverse(int i, int j, vector<int> &nums){
        while(i<j){
            swap(nums[i++], nums[j--]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        //We are applying the same concept as bottom one but here to optimize space complexity we will be using two pointers to reverse the array...
        int n = nums.size();
        k = k%n;
        reverse(0, n-1, nums);
        reverse(0, k-1, nums);
        reverse(k, n-1, nums);

        // stack<int>s1;
        // stack<int>s2;
        // int size=nums.size();
        // if(k>=size){
        //     k=k%size;
        // }
        // int count=0;
        // for(int i=size-1;i>=0;i--){
        //     if(count<k){
        //         s1.push(nums[i]);
        //         count++;
        //         nums.pop_back();
        //     }
        //     else{
        //         s2.push(nums[i]);
        //         nums.pop_back();
        //     }
        // }
        // while(!s1.empty()){
        //     nums.push_back(s1.top());
        //     s1.pop();
        // }
        // while(!s2.empty()){
        //     nums.push_back(s2.top());
        //     s2.pop();
        // }
    }  

};