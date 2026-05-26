class Solution {
    bool isLower(char ch){
        if(ch>='a' && ch<='z') return true;
        return false;
    }
public:
    int numberOfSpecialChars(string word) {
        set<int> lower, upper;
        int count = 0;

        for(int i=0; i<word.length(); i++){
            if(isLower(word[i])) lower.insert(word[i]);
            else upper.insert(word[i]+32);
        }
        for(char ch: lower){
            if(upper.count(ch)) count++;
        }
        return count;
    }
};