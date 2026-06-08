class Solution {
    bool solve(string& s, unordered_set<string>& dic, int i, vector<int>& dp){
        if(i == s.length()) return true;
        if(dp[i] != -1) return dp[i];

        for(int ind=i; ind<s.length(); ind++){
            string stray = s.substr(i, ind - i + 1);
            bool ans = false;
            if(dic.find(stray) != dic.end()) ans = solve(s, dic, ind+1, dp);
            if(ans) return dp[i] = true;
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic;
        for(int i=0; i<wordDict.size(); i++){
            dic.insert(wordDict[i]);
        }
        
        vector<int> dp(s.length(), -1);
        return solve(s, dic, 0, dp);
    }
};