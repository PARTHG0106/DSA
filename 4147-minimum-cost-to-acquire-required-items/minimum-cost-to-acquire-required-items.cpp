class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if(costBoth > cost1 + cost2){
            return (1LL * cost1 * need1 + 1LL * cost2 * need2);
        }
        long long smallNeed = min(need1, need2);
        ans += 1LL * (smallNeed * costBoth);
        smallNeed = max(need1, need2) - min(need1, need2);
        if(need1 > need2){
            if(costBoth < cost1) return ans + smallNeed * costBoth;
            else return ans + 1LL * (smallNeed * cost1);
        }
        else{
            if(costBoth < cost2) return ans + smallNeed * costBoth;
            else return ans + 1LL * (smallNeed * cost2);
        }
        return ans;
    }
};