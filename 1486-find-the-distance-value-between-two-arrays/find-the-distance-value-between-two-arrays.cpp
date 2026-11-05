class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0, i = 0, j = 0, m = arr1.size(), n = arr2.size();
        while(i < m && j < n){
            if(abs(arr1[i] - arr2[j]) > d){
                if(j == n - 1) ans++;
                j++;
            }
            else if(abs(arr1[i] - arr2[j]) <= d){
                i++;
                j = 0;
            }
            if(j == n) j = 0, i++;
        }
        return ans;
    }
};