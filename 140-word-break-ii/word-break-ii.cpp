class Solution {
    void solve(string& s, unordered_set<string>& dic, int i, string path, vector<string>& ans){
        if(i == s.length()){
            path.resize(path.size()-1);
            ans.push_back(path);
            return ;
        }

        for(int ind=i; ind<s.length(); ind++){
            string temp = s.substr(i, ind-i+1);
            if(dic.count(temp)){
                int size = path.size();
                path += temp + " ";
                solve(s, dic, ind+1, path, ans);
                path.resize(size);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string path = "";
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        solve(s, dic, 0, path, ans);
        return ans;
    }
};