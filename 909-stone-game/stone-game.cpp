class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Because the piles array has an even length, Alice can always force taking either all even, or all odd indexed piles.
        // Since Alice always has a choice between the two parities, she can always obtain the parity with the larger total sum.
        // Consequently, Bob is left with the parity having the smaller total sum.
        // Since the total number of stones is odd, then one parity has a strictly larger total sum. Therefore, Alice is guaranteed to collect more stones than Bob.
        return true;
    }
};