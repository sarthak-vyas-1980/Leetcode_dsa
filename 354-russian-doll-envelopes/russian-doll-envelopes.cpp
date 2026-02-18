class Solution {
    static bool greater(vector<int>& a1, vector<int>& a2) {
        if(a1[0] == a2[0]) return a1[1] > a2[1];
        return a1[0] < a2[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        //sort
        sort(envelopes.begin(), envelopes.end(), greater);
        // Longest Increasing Subsequence!!!
        if(n==0) return n;
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for(int i=1; i<n; i++){
            if(envelopes[i][1] > ans.back()) ans.push_back(envelopes[i][1]);
            else{
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }
};