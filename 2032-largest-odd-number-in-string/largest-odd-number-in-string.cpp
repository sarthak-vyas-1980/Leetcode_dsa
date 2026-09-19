class Solution {
public:
    string largestOddNumber(string num) {
        int size = num.length();

        for(int i=0; i<size; i++){
            int digit = num.back() - '0';
            if(digit % 2 == 1) return num;
            else num.pop_back();
        }
        return num;
    }
};