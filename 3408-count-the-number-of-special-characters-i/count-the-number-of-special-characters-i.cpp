class Solution {
    bool isLower(char ch){
        if(ch>='a' && ch<='z') return true;
        return false;
    }
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        int count = 0;

        for(int i=0; i<word.length(); i++){
            if(isLower(word[i])){
                lower[word[i]-'a'] = 1;
                if(upper[word[i]-'a'] == 1){
                    count++;
                    upper[word[i]-'a'] = -1;
                } 
            }
            else{
                if(upper[word[i]-'A'] == -1) continue;
                upper[word[i]-'A'] = 1;
                if(lower[word[i]-'A'] == 1){
                    count++;
                    upper[word[i]-'A'] = -1;
                } 
            }
        }
        return count;
    }
};