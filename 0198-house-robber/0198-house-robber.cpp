// class Solution {
// public:
//     int dp[101];

//     int solve(vector<int>& nums) {
//         if (n == 0) {
//             return 0;
//         }

//         if (n == 1) {
//             return 1;
//         }

//         dp[0] = nums[0];
//         dp[1] = nums[1];

//         for (int i = 2; i <= nums.size(); i++) {
//             dp[i] = max(dp[i - 2], dp[i - 1]);
//         }

//         return dp[n];
//     }
//     int rob(vector<int>& nums) {
//         memset(dp, -1, sizeof(dp));
//         return solve(nums);
//     }
// };

class Solution {
public:
    int dp[101];

    int solve(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }

    int rob(vector<int>& nums) { return solve(nums); }
};
