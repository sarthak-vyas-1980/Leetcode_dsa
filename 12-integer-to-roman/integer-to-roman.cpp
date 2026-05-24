class Solution {
public:
    string intToRoman(int num) {
        string number = to_string(num);
        int size = number.length();
        string ans;

        while(size){
            if(size == 4){
                int num = (number[0]-'0') % 5;
                if(number[0] > '5'){
                    if(num == 4){
                        ans.push_back('M');
                        ans.push_back('Q');
                    }
                    else{
                        ans.push_back('D');
                        for(int i=0; i<num; i++) ans.push_back('C');
                    }         
                }
                else if(number[0] == '5') ans.push_back('D');
                else{
                    if(num == 4){
                        ans.push_back('M');
                        ans.push_back('Q');
                    }
                    else for(int i=0; i<num; i++) ans.push_back('M');
                }
                size--;
                number = number.substr(1);
            }
            if(size == 3){
                int num = (number[0]-'0') % 5;
                if(number[0] > '5'){
                    if(num == 4){
                        ans.push_back('C');
                        ans.push_back('M');
                    }
                    else{
                        ans.push_back('D');
                        for(int i=0; i<num; i++) ans.push_back('C');
                    }         
                }
                else if(number[0] == '5') ans.push_back('D');
                else{
                    if(num == 4){
                        ans.push_back('C');
                        ans.push_back('D');
                    }
                    else for(int i=0; i<num; i++) ans.push_back('C');
                }
                size--;
                number = number.substr(1);
            }
            if(size == 2){
                int num = (number[0]-'0') % 5;
                if(number[0] > '5'){
                    if(num == 4){
                        ans.push_back('X');
                        ans.push_back('C');
                    }
                    else{
                        ans.push_back('L');
                        for(int i=0; i<num; i++) ans.push_back('X');
                    }         
                }
                else if(number[0] == '5') ans.push_back('L');
                else{
                    if(num == 4){
                        ans.push_back('X');
                        ans.push_back('L');
                    }
                    else for(int i=0; i<num; i++) ans.push_back('X');
                }
                size--;
                number = number.substr(1);
            }
            if(size == 1){
                int num = (number[0]-'0') % 5;
                if(number[0] > '5'){
                    if(num == 4){
                        ans.push_back('I');
                        ans.push_back('X');
                    }
                    else{
                        ans.push_back('V');
                        for(int i=0; i<num; i++) ans.push_back('I');
                    }         
                }
                else if(number[0] == '5') ans.push_back('V');
                else{
                    if(num == 4){
                        ans.push_back('I');
                        ans.push_back('V');
                    }
                    else for(int i=0; i<num; i++) ans.push_back('I');
                }
                size--;
                number = number.substr(1);
            }
            
        }
        return ans;
    }
};