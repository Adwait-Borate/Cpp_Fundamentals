class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;

        int dp[n + 1][d + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= d; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        dp[0][0] = 0;

        for (int day = 1; day <= d; ++day) {
            for (int i = day; i <= n; ++i) {
                int maxDifficulty = 0;
                for (int j = i - 1; j >= day - 1; --j) {
                    maxDifficulty = max(maxDifficulty, jobDifficulty[j]);
                    if (dp[j][day - 1] != INT_MAX) {
                        dp[i][day] =
                            min(dp[i][day], dp[j][day - 1] + maxDifficulty);
                    }
                }
            }
        }

        return dp[n][d] == INT_MAX ? -1 : dp[n][d];
    }
};
