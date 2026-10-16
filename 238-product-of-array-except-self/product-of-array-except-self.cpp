class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int c0 = count(nums.begin(), nums.end(), 0), n = nums.size();
        if (c0 > 1) return vector<int> (n, 0);
        int track0 = 0;
        if(c0 == 1) track0 = 1;
        int32_t totalProd = 1;
        for(int x : nums){
            if(x != 0) totalProd *= x;
        }
        vector<int32_t> ans(n);
        for(int i = 0; i < n; i++){
            if(nums[i] != 0 && track0 == 1) ans[i] = 0;
            else if(nums[i] != 0 && track0 == 0) ans[i] = totalProd / nums[i];
            else if(nums[i] == 0) ans[i] = totalProd;
        }
        return ans;
    }
};
