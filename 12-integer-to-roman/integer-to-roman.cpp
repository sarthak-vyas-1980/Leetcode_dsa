class Solution {
public:
    string intToRoman(int num) {
        int i = 0, values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        while(num){
            if(num >= values[i]){
                ans += roman[i];
                num -= values[i];
            }
            else i++;
        }
        return ans;
    }
};