class Solution {
    bool isSmall(char ch){
        if(ch>='a' && ch<='z') return true;
        return false;
    }
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> lower;
        unordered_map<char, int> upper;
        int ans = 0; 

        for(int i=0; i<word.length(); i++){
            if(isSmall(word[i])) lower[word[i]] = i;
            else {
                if(!upper.count(word[i]+32)) upper[word[i]+32] = i;
            }
        }
        for(char ch='a'; ch<='z'; ch++){
            if(lower.count(ch) && upper.count(ch) && lower[ch] < upper[ch]) ans++;
        }
        return ans;
    }
};