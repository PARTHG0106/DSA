class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int longLen = 1, i = 0, j = 1, ans = 0;
        cout << "Increasing:\n";
        while (j < n && i < j) {
            if (nums[i] < nums[j]) {
                cout << longLen << " ";
                longLen++;
            } else {
                ans = max(ans, longLen);
                longLen = 1;
            }
            ans = max(ans, longLen);
            i++;
            j++;
        }
        cout << "Decreasing:\n";
        i = 0, j = 1, longLen = 1;
        while (j < n && i < j) {
            if (nums[i] > nums[j]) {
                cout << longLen << " ";
                longLen++;
            } else {
                ans = max(ans, longLen);
                longLen = 1;
            }
            ans = max(ans, longLen);
            i++;
            j++;
        }
        return ans;
    }
};