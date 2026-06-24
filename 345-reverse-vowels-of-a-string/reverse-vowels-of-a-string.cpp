class Solution {
    char turnLower(char ch){
        if(ch >= 'a' && ch <= 'z') return ch;
        return ch - 'A' + 'a';
    }
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        int st = 0, e = s.length()-1;

        while(st < e){
            while(st < e && !isVowel(turnLower(s[st]))) st++;
            while(e > st && !isVowel(turnLower(s[e]))) e--;
            if(st < e) swap(s[st++], s[e--]);
        }
        return s;
    }
};