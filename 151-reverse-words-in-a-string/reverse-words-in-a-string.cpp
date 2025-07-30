class Solution {
public:
    string reverseWords(string s) {
        vector<string> use;
        string temp="";
        for(int i=0 ; i<s.length() ; i++){
            if(s[i] != ' '){
                temp.push_back(s[i]);
            }
            else if(temp!=""){
                use.push_back(temp);
                temp = "";
            }
        }
        if(temp!="") use.push_back(temp);
        string ans="";
        for( int i=use.size()-1 ; i>=0; i--){
            if(use[i]!=" "){
                ans += use[i];
                if(i>0) ans.push_back(' ');
            }
        }
        return ans;
    }
};

