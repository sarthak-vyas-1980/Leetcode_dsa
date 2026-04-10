class Solution {
    bool palindrome(string s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans, vector<string> temp, string s, int i){
        if(i >= s.length()){
            ans.push_back(temp);
            return ;
        }
        for(int ind=i; ind<s.length(); ind++){
            if(palindrome(s, i, ind)){
                temp.push_back(s.substr(i, ind - i +1));
                solve(ans, temp, s, ind+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.length() == 0) return ans;
        vector<string> temp;
        solve(ans, temp, s, 0);
        return ans;
    }
};