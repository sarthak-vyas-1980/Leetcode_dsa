class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int min = strs[0].length();
        for (int i=0 ; i<strs.size() ; i++){
            string temp = strs[i];
            int count = temp.length();
            if( count < min ) min = count;
        }

        string ans="";
        int index = 0;
        for (int i=0 ; i<min ; i++){
            bool check= true;
            string start = strs[0];
            for (int j=0 ; j<strs.size() ; j++){
                string temp = strs[j];
                char ch = temp[index];
                if ( start[index] != ch){ 
                    check= false;
                    break;
                };
            }
            if(!check) break;
            ans.push_back(start[index++]);
            }
        return ans;
    }
};