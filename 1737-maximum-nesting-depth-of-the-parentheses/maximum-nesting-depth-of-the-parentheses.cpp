class Solution {
public:
    int maxDepth(string s) {
        int countP = 0, maxi = 0;
        for(char c : s){
            if(c == '(') countP++;
            else if(c == ')') countP--;
            maxi = max(countP, maxi);
        }
        return maxi;
    }
};