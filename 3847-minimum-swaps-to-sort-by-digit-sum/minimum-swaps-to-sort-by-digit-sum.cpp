class Solution {
public:
    int sumDigits(int n){
        int ans = 0;
        while(n){
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> og = nums;
        unordered_map<int, int> uno_mp;
        for(int x : nums) uno_mp[x] = sumDigits(x);
        sort(begin(nums), end(nums), [&uno_mp](const auto &a, const auto &b){ 
            if(uno_mp[a] != uno_mp[b]) return uno_mp[a] < uno_mp[b];
            return a < b;
        });

        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); i++)
            pos[nums[i]] = i;
        
        int n = nums.size(), swaps = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int j = i, cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = pos[og[j]];
                cycle++;
            }

            swaps += cycle - 1;
        }
        return swaps;
    }
};