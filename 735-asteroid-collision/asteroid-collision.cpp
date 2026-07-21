class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for(int ast: asteroids){
            if(stack.empty()) stack.push_back(ast);
            else{
                bool back = stack.back() < 0;
                bool curr = ast < 0;

                if((back && curr) || (!back && !curr) || (back && !curr)) stack.push_back(ast);
                else{
                    bool flag = false;
                    while(!stack.empty() && stack.back() > 0){
                        if(stack.back() == -1*ast){
                            flag = true;
                            stack.pop_back();
                            break;
                        }
                        else if(stack.back() > -1*ast){
                            flag = true;
                            break;
                        }
                        else stack.pop_back();
                    }
                    if(!flag) stack.push_back(ast);
                } 
            }
        }
        return stack;
    }
};