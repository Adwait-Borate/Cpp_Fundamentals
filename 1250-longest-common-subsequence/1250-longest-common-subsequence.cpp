class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(string& text1, string& text2, int n, int m) {

        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        int result = 0;

        if (text1[n - 1] == text2[m - 1]) {
            result = 1 + solve(text1, text2, n - 1, m - 1);
        } else {
            result = max(solve(text1, text2, n, m - 1),
                         solve(text1, text2, n - 1, m));
        }

        return dp[n][m] = result;
    }

    int longestCommonSubsequence(string text1, string text2) {
        n = text1.length();
        m = text2.length();

        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

        return solve(text1, text2, n, m);
    }
};
