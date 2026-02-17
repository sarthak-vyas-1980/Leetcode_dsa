class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int> curr(n+1, 0);
        // vector<int> next(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=i; j++){
                int incl = satisfaction[i]*(j+1) + curr[j+1];
                int excl = curr[j]; 
                curr[j] = max(incl, excl);
            }
            // next = curr;
        }
        return curr[0];
    }
};