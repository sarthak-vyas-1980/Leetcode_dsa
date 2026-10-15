class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //The middle part(n-k) left-out is what we want to find b/c if we minimize that, the other two ends' part will be auotomatically maximized
        int n = cardPoints.size();
        k = n - k;
        int sum = 0, ans = 0, totalSum = 0;

        for(int i=0; i<n; i++){
            sum += cardPoints[i];
            totalSum += cardPoints[i];
            if(i == k-1) ans = sum;

            if(i >= k){
                sum -= cardPoints[i-k];
                ans = min(ans, sum);   
            }
        }
        return totalSum - ans;
    }
};