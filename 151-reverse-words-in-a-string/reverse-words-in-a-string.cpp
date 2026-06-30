class Solution {
public:
    string reverseWords(string s) {
        string ans = "", word = "";

        int i = s.length()-1;
        while(i >= 0 && s[i] == ' ') i--;

        int j = 0;
        while(j < s.length() && s[j] == ' ') j++;

        for(; i>=j; i--){
            if(s[i] == ' '){
                reverse(word.begin(), word.end());
                ans = ans + word + " ";
                word = "";
                while(i-1 >= 0 && s[i-1] == ' ') i--;
            } 
            else word.push_back(s[i]);
            
        }
        reverse(word.begin(), word.end());
        return ans + word;
    }
};