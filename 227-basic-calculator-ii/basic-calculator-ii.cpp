class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0) return 0;
        /* Stack is used in previous soln to follow BODMASS as multi and divi will happen straigh away but add and sub will 
        happen at last after all higher priority operations have occured and that's why we store it in vector and perform 
        after the whole traversal of number and other operations!!! */ 

        /*Right now lastNumber is added to total only when the current sign is +,- which is actually the previous number to 
        currentNumber, and now also the currentNumber will not be added to total because if the future operation is a *,/ we 
        will need to process it with lastNumber so we store currentNumber as lastNumber for +,- and update lastNumber for *,/
        */
        long currentNumber = 0, lastNumber = 0, total = 0;
        char sign = '+';

        for (int i = 0; i < s.length(); i++) {
            char currentCharacter = s[i];

            // 1. Build the multi-digit number
            if (isdigit(currentCharacter)) { 
                currentNumber = (currentNumber * 10) + (currentCharacter - '0');
            }
            // 2. If it's an operator or the end of the string, apply the previous sign
            if (!isdigit(currentCharacter) && !isspace(currentCharacter) || i == s.length() - 1) {
                if (sign == '+' || sign == '-') {
                    total += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                sign = currentCharacter;
                currentNumber = 0;
            }
        }
        return lastNumber + total;
    }
};