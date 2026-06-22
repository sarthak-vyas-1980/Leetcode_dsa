class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int offset = 10000;
        vector<int> arr(200001, 0);
        for(int num: nums){
            arr[num+offset]++;
        }

        int sum = 0;
        bool isSelected = false;
        for(int i=0; i<arr.size(); i++){
            if(!arr[i]) continue;
            
            while(arr[i]){
                if(!isSelected){ 
                    sum += i - offset;
                    isSelected = true;
                }
                else{
                    isSelected = false;
                }
                arr[i]--;
            }
        }
        return sum;
    }
};