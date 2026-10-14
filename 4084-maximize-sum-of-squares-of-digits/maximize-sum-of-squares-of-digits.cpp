class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num * 9 < sum) return "";
        int nines = sum / 9;
        sum %= 9;
        string ans;
        ans.append(nines, '9');
        if(sum)ans += char('0' + sum);
        ans.append(num - nines - (sum > 0), '0');
        return ans;
    }
};