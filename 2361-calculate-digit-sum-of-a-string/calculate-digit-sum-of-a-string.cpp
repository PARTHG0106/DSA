class Solution {
public:
    void dS(string &s, int k){
        int n = s.length(), i, j;
        string mS = "";
        for(i = 0; i < n; i += k){
            int sum = 0;
            for(j = i; j < min(i + k, n); j++){
                sum += s[j] - '0';
            }
            mS += to_string(sum);
        }
        s = mS;
    }
    string digitSum(string s, int k) {
        int n = s.length();
        if(k >= n) return s;
        while(s.length() > k){
            dS(s, k);
        }
        return s;
    }
};