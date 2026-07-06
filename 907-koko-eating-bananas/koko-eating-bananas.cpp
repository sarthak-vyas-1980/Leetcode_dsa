class Solution {
    long long check(vector<int>& piles, int mid){
        long long count = 0;
        for(int i=0; i<piles.size(); i++){
            if(mid >= piles[i]) count++;
            else count += piles[i]%mid == 0 ? piles[i]/mid : piles[i]/mid + 1;
        }
        return count;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Sorting is not needed for binary search on the answer space
        int i = 1, j = INT_MIN;
        for(int pile: piles) j = max(j, pile);
        int mid = i + (j - i)/2;

        int ans = j;
        while(i<=j){
            long long count = check(piles, mid);
            // 2. Merged (count == h) and (count < h) to find the absolute minimum speed
            if(count <= h){
                ans = mid;
                j = mid - 1;
            }
            else i = mid + 1;
            mid = i + (j - i)/2;
        }
        return ans;
    }
};