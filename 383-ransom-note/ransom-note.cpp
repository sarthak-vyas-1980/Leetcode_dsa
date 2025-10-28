class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ran;
        unordered_map<char, int> mag;

        for (int i=0; i<ransomNote.length(); i++){
            ran[ransomNote[i]]++;
        }
        for (int i=0; i<magazine.length(); i++){
            mag[magazine[i]]++;
        }
        for (char i='a'; i<='z'; i++){
            if(ran[i]>mag[i]) return false;
        }
        return true;
    }
};