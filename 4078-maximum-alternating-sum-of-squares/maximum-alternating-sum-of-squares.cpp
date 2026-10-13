class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            ans += 1LL * (nums[j] * nums[j]);
            if(i < j) ans -= 1LL * (nums[i] * nums[i]), i++;
            j--;
        }
        return ans;
    }
};