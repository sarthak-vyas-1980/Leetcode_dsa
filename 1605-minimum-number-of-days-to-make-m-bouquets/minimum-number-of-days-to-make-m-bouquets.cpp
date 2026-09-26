class Solution {
    bool isPossible(vector<int>& bloomDay, int m, int k, int day){
        int count = 0;
        for(int plant: bloomDay){
            if(count == k){
                m--;
                count = 0;
                if(m == 0) return true;
            }

            if(plant - day <= 0) count++;
            else count = 0;
        }
        if(count >= k) m--; // for last one
        return m <= 0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)m * k > bloomDay.size()) return -1;
        int i = 1, j = *max_element(bloomDay.begin(), bloomDay.end());

        while(i < j){
            int mid = i + (j - i)/2;
            if(isPossible(bloomDay, m, k, mid)) j = mid;
            else i = mid + 1;
        }
        return i;
    }
};