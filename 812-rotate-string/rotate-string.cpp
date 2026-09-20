class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int size = s.length();

        for(int i=0; i<size; i++){
            int j = i, ind = 0, count = 0;
            for(int k=0; k<size; k++){
                if(s[ind++] == goal[j]) count++;
                j = (j+1) % size;
            }
            if(count == size) return true;
        }
        return false;
    }
};