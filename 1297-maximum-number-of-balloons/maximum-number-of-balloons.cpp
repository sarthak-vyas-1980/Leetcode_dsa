class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        unordered_map<char, int> match;

        for(char ch: text){
            freq[ch]++;
        }
        for(char ch: "balloon"){
            if(ch == '\0') break;
            match[ch]++;
        }
        
        int ans = INT_MAX;
        for(auto letter: match){
            ans = min(ans, (freq[letter.first] / letter.second));
        }
        return ans;
    }
};