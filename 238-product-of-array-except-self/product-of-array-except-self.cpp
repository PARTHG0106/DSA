class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int track0 = 0, c0 = 0;
        int32_t totalProd = 1;
        for(int x : nums){
            if(x != 0) totalProd *= x;
            else c0++;
            if(c0 == 1) track0 = 1;
            else if(c0 > 1) return vector<int> (n, 0);
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
