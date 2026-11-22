class Solution {
public:
    bool checkString(string s) {
        bool aS = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'a') aS = 1;
            else if(aS) return false;
        }
        return true;
    }
};