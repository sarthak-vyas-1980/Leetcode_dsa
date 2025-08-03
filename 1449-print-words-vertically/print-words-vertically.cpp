#include<vector>
#include<string>

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> help;
        vector<string> ans;
        if(s.length()==0) return ans;

        string temp;
        int maxLen=0;
        for(char c : s){
            if(c==' '){
                help.push_back(temp);
                if(temp.length()>maxLen) maxLen = temp.length(); 
                temp="";
            } else {
                temp.push_back(c);
            }
        }
        if(temp.length()!=0){ //...last element
            if(temp.length()>maxLen) maxLen = temp.length();
            help.push_back(temp);
        }  

        for(int i=0; i<maxLen; i++){
            string a="";
            for(int j=0; j<help.size(); j++){
                string str=help[j];
                if(i>=str.length()){
                    a.push_back(' ');
                }
                else{
                    a.push_back(str[i]);
                }
            }
            while(!a.empty() && a.back()==' ') a.pop_back();
            ans.push_back(a);
        }
        return ans;
    }
};