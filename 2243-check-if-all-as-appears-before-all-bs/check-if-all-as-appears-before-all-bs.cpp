class Solution {
public:
    bool checkString(string s) {
        bool aS = 0, bE = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'b' && aS == 0) continue;
            else if(s[i] == 'b' && aS != 0) return false;
            else if(s[i] == 'a'){
                bE = 1;
                aS = 1;
                continue;
            }
        }
        return true;
    }
};