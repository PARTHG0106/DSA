class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(1LL * num * 9 < sum) return "";
        string n = "";
        while(num--){
            int d = min(sum, 9);
            n += char('0' + d);
            sum -= d;
        }
        return n;
    }
};