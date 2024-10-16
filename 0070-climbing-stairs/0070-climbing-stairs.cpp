class Solution {
public:
    int dp[46];
    int solve(int n) {
        if (n == 0) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }
        int step1 = 0, step2 = 0;

        if (n - 1 >= 0) {
            step1 = solve(n - 1);
        }

        if (n - 2 >= 0) {
            step2 = solve(n - 2);
        }

        return dp[n] = step1 + step2;
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
