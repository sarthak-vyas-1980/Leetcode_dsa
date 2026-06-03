class Solution {
public:
    int minDistance(string word1, string word2) { //Count operations and don't simulate them
        if(word1.length() == 0) return word2.length();
        if(word2.length() == 0) return word1.length();
        
        vector<int> curr(word2.length()+1, 0);
        vector<int> next(word2.length()+1, 0);

        for(int j=0; j<word2.length(); j++){
            next[j] = word2.length() - j;
        }
        for(int i=word1.length()-1; i>=0; i--){
            for(int j=word2.length()-1; j>=0; j--){
                curr[word2.length()] = word1.length() - i;
                int ans = 0;
                if(word1[i] == word2[j]) ans = next[j+1];
                else{
                    int insert = 1 + curr[j+1];
                    int Delete = 1 + next[j];
                    int replace = 1 + next[j+1];
                    ans = min(insert, min(Delete, replace));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
};