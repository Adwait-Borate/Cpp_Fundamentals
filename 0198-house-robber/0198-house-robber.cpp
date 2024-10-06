class Solution {
public:
    // int solve(vector<int>& nums, int i) {
    //     if (i >= nums.size())
    //         return 0;
    //     int steal = nums[i] + solve(nums, i + 2);
    //     int skip = 0 + solve(nums, i + 1);

    //     return max(steal, skip);
    // }

    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1) {
            return dp[i];
        }
        int steal = nums[i] + solve(nums,i+2,dp);
        int skip = 0 + solve(nums,i+1,dp);

        return dp[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, 0, dp);
    }
};