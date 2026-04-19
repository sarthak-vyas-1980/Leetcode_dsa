class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());   //or set.insert while iterating values
        int answer = 0;
        for(int num: s){   //set stores only non-redundant elements!!
            if(s.find(num-1) == s.end()){
                int count = 1;
                int itr = num + 1;
                while(s.find(itr) != s.end()){
                    count++;
                    itr++;
                }
                answer = max(answer, count);
            }
        }
        return answer;
    }
};