class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        unordered_map<char, int> map1, map2;

        for(char word: word1){
            map1[word]++;
        }
        for(char word: word2){
            if(!map1.count(word)) return false;
            map2[word]++;
        }

        unordered_map<int, int> check;
        for(auto row: map1){
            check[row.second]++;
        }
        for(auto row: map2){
            if(check.count(row.second)) check[row.second]--;
            if(check[row.second] == 0) check.erase(row.second);
        }
        return check.empty();
    }
};