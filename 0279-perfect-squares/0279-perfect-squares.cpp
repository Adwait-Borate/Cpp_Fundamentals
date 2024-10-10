// class Solution {
// public:
//     int helper(int n) {
//         int mini = INT_MAX;
//         int result;
//         // base case
//         if (n == 0) {
//             return 0;
//         }

//         for (int i = 1; i * i <= n; i++) {
//             result = 1 + helper(n - i * i);
//             mini = min(mini, result);
//         }
//         return mini;
//     }
//     int numSquares(int n) { return helper(n); }
// };

class Solution {
public:
    int dp[10001];
    int helper(int n) {
        int mini = INT_MAX;
        int result;
        // base case
        if (n == 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        for (int i = 1; i * i <= n; i++) {
            result = 1 + helper(n - i * i);
            mini = min(mini, result);
        }
        return dp[n] = mini;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};