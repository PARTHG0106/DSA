class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(begin(nums), end(nums)), moves = 0;
        for(auto& x : nums){
            while(x != maxi) x++, moves++;
        }
        return moves;
    }
};