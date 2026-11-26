class Solution {
public:
    bool canAliceWin(int n) {
        bool A = 0;
        int sub = 9;
        n -= 10;
        while(n >= 0){
            n -= sub;
            sub--;
            A = (A == 1) ? 0 : 1;
        }
        return A;
    }
};