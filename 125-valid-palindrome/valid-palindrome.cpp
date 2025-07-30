class Solution {
    bool isLegal(char ch){
        if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') ){
            return true;
        }
        return false;
    }
    char toLowercase(char ch){
        if( (ch>='a' && ch<='z') || (ch>='0' && ch<='9') ){
            return ch;
        } else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
public:
    bool isPalindrome(string s) {
        string temp="";
        for (int i=0 ; i<s.length() ; i++){
            if(isLegal(s[i])){
                temp.push_back(s[i]);
            }
        }
        int i=0 , j=temp.length()-1;
        while(i<=j){
            if(toLowercase(temp[i++]) != toLowercase(temp[j--])) return false;
        }
        return true;
    }
};