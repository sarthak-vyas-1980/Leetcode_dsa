class Solution {
public:
    string removeDuplicates(string s) {
        if(s.length()==1) return s;
        string ans="";
        for(int i=0; i<s.length();i++){
            if(!ans.empty() && s[i]==ans.back()){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};