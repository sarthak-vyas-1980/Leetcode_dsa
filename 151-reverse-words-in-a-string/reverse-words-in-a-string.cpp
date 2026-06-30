class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";

        int i = 0;
        while(i < s.length()){
            if(s[i] == ' '){
                i++;
                continue;
            } 
            while(i < s.length() && s[i] != ' ') word.push_back(s[i++]);
            ans = word + " " + ans;
            word = "";
        }
        ans.pop_back();
        return ans;
    }
};