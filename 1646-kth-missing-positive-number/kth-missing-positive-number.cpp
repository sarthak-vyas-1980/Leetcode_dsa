class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int counter = 1, i = 0;
        while(true){
            if(i < arr.size() && counter == arr[i]){
                i++;
            } else {
                k--;
                if(k== 0) return counter;
            }
            counter++;
        }
        return counter;
    }
};