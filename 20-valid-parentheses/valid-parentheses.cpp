class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                v.push_back(s[i]);
            }
            else{
                if(!v.empty() && ((s[i] == '}' && v.back() == '{') || (s[i] == ']' && v.back() == '[') || (s[i] == ')' && v.back() == '('))){
                    v.pop_back();
                }
                else{
                    return false;
                }
            }
        }
        if(v.empty()) return true;
        else return false;
    }
};