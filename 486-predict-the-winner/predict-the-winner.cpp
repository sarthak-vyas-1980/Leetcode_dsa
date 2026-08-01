class Solution {
    bool solve(vector<int>&nums, int s, int e, int score1, int score2, bool turn){
        if(s > e){
            if(score1 >= score2) return true;
            return false;
        }

        if(turn){
            bool ans1 = solve(nums, s+1, e, score1 + nums[s], score2, 0);
            bool ans2 = solve(nums, s, e-1, score1 + nums[e], score2, 0);
            return ans1 || ans2; // game changer - player1 is playing optimally
        }
        else{
            bool ans1 = solve(nums, s+1, e, score1, score2 + nums[s], 1);
            bool ans2 = solve(nums, s, e-1, score1, score2 + nums[e], 1);
            return ans1 && ans2; // game changer - player2 is playing optimally
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1, 0, 0, 1);
    }
};