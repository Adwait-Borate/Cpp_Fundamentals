// class Solution {
// public:
// //RECURSION
// typedef long long ll;
//     ll solve(int idx, vector<int>& nums, bool flag) {
//         if (idx >= nums.size()) {
//             return 0;
//         }
//         ll skip = solve(idx + 1, nums, flag);
//         ll val = nums[idx];
//         if (flag == false) {
//             val = -val;
//         }
//         ll take = val + solve(idx+1, nums, !flag);
//         return max(skip, take);
//     }
//     long long maxAlternatingSum(vector<int>& nums) {
//         ll n = nums.size();
//         return solve(0, nums, true);
//     }
// };


class Solution {
public:
    typedef long long ll;

    //MEMOIZATION
    ll solve(int idx, vector<int>& nums, bool flag, ll dp[][2]) {
        if (idx >= nums.size()) {
            return 0;
        }

        if (dp[idx][flag] != -1) {
            return dp[idx][flag];
        }

        ll skip = solve(idx + 1, nums, flag, dp);

        ll val = nums[idx];
        if (!flag) {
            val = -val;
        }
        ll take = val + solve(idx + 1, nums, !flag, dp);

        return dp[idx][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        ll n = nums.size();

        ll dp[n][2];
        memset(dp, -1, sizeof(dp));

        return solve(0, nums, true, dp);
    }
};

