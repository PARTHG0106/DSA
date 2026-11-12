class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = size(nums), inc = 1, dec = 1, i = 0, j = 1, ans = 0;
        if(n == 1) return 1;
        while(j < n){
            if(nums[i] < nums[j]){
                inc++;
                dec = 1;
            }
            else if(nums[i] > nums[j]){
                dec++;
                inc = 1;
            }
            else {
                inc = 1;
                dec = 1;
            }
            i++, j++;
            ans = max({ans, inc, dec});
        }
        return ans;
    }
};