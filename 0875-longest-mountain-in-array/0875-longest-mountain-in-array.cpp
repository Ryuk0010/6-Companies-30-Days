class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        int ans = 0;

        for (int i = 0; i < n-1; i++) {
            if (arr[i] < arr[i + 1]) {
                dp1[i+1] = 1 + dp1[i];
            }
        }
        for (int i = n-1; i > 0; i--) {
            if (arr[i] < arr[i - 1]) {
                dp2[i-1] = 1 + dp2[i];
            }
        }
        for(int i = 0; i < n; i++){
            if(dp1[i] > 1 && dp2[i] > 1)
            ans = max(ans, dp1[i]+dp2[i] -1);
        }
        return ans;
    }
};