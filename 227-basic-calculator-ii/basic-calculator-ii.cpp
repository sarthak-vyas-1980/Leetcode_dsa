class Solution {
public:
    int calculate(string s) {
        int length = s.length();
        if (length == 0) return 0;
        
        vector<int> stack; 
        long currentNumber = 0;
        char sign = '+';

        for (int i = 0; i < length; i++) {
            char currentCharacter = s[i];
            
            // 1. Build the multi-digit number
            if (isdigit(currentCharacter)) {
                currentNumber = (currentNumber * 10) + (currentCharacter - '0');
            }
            
            // 2. If it's an operator or the end of the string, apply the previous sign
            if (!isdigit(currentCharacter) && !isspace(currentCharacter) || i == length - 1) {
                if (sign == '+') {
                    stack.push_back(currentNumber);
                } else if (sign == '-') {
                    stack.push_back(-currentNumber);
                } else if (sign == '*') {
                    int lastNumber = stack.back();
                    stack.pop_back();
                    stack.push_back(lastNumber * currentNumber);
                } else if (sign == '/') {
                    int lastNumber = stack.back();
                    stack.pop_back();
                    stack.push_back(lastNumber / currentNumber);
                }
                sign = currentCharacter;
                currentNumber = 0;
            }
        }

        int result = 0;
        for (int i : stack) result += i;
        return result;
    }
};