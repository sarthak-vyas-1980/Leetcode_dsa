// class Solution {
// public:
//     string simplifyPath(string path) {
    //     stack<string> s;
    //     int i = 0;
    //     while(i<path.length()){
    //         if(path[i]=='/'){
    //             int j =  i+1;
    //             while(j<path.length() && path[j]=='/'){
    //                 j++;
    //             }
    //             if(path[j]=='.' && j+1<path.length() && path[j+1]=='.'){
    //                 if(j+2<path.length() && path[j+2]=='.'){
    //                     string temp = "...";
    //                     j=j+3;
    //                     while(j<path.length() && path[j++]!='/') temp.push_back(path[j]);
    //                     s.push(temp);
    //                     i=j;
    //                 }
    //                 else {
    //                     s.pop();
    //                     i = j+2;
    //                 }
    //             }
    //             else if(path[j]=='.' && j+1<path.length() && path[j+1]!='.'){
    //                 i = j+1;
    //             }
    //             else{
    //                 string temp = "";
    //                 while(j<path.length() && path[j++]!='/') temp.push_back(path[j]);
    //                 i=j-1;
    //                 s.push(temp);
    //             }
    //         }
    //     }
    //     stack<string> s1;
    //     while(!s.empty()){
    //         string val = s.top();
    //         s.pop();
    //         s1.push(val);
    //     }
    //     string ans="/";
    //     while(!s1.empty()){
    //         ans += s1.top();
    //         s1.pop();
    //         if(!s1.empty()) ans.push_back('/');
    //     }
    //     return ans;
    // }
    
// };
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts;
        int n = path.size();
        for (int i = 0; i < n; ) {
            // skip any '/' characters
            while (i < n && path[i] == '/') ++i;
            if (i >= n) break;
            int j = i;
            while (j < n && path[j] != '/') ++j;
            string token = path.substr(i, j - i);
            if (token == "." || token.empty()) {
                // do nothing
            } else if (token == "..") {
                if (!parts.empty()) parts.pop_back();
            } else {
                // normal directory name (including names like "..." are valid dir names)
                parts.push_back(token);
            }
            i = j;
        }

        if (parts.empty()) return "/";

        string ans;
        for (const string &p : parts) {
            ans += '/';
            ans += p;
        }
        return ans;
    }
};
