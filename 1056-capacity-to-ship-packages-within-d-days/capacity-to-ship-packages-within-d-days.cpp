class Solution {
    bool isPossible(vector<int>& weights, int days, int capacity){
        int day = 1, weight = 0;
        int i = 0;
        
        while(i < weights.size()){
            if(weight + weights[i] <= capacity) weight += weights[i];
            else{
                weight = weights[i];
                day++;
                if(day > days) return false;
            }    
            i++;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(weights, days, mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};