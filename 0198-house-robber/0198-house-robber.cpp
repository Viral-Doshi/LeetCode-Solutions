class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 2)
            return *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return max(dp[n-2], dp[n-1]);

    }
};