class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(1LL * num * 9 < sum) return "";
        int nines = sum / 9;
        sum %= 9;
        return (string(nines, '9') + char('0' + sum) + string(num, '0')).substr(0, num);
    }
};