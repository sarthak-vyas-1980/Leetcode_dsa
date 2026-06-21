class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = INT_MIN;
        for(int cost: costs){
            maxi = max(maxi, cost);
        }

        vector<int> arr(maxi+1, 0);
        for(int cost: costs){
            arr[cost]++;
        }

        int count = 0;
        for(int i=1; i<arr.size(); i++){
            if(coins < i) break;
            if(arr[i]){
                while(coins >= i && arr[i]){
                    count++;
                    coins -= i;
                    arr[i]--;
                }
            }
        }
        return count;
    }
};