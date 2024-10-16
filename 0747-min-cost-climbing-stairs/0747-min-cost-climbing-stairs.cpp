class Solution {
public:
    int dp[1001];
    int solve(int idx, vector<int>& cost) {
        if (idx >= cost.size()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int step1 = 0, step2 = 0;
        step1 = cost[idx] + solve(idx + 1, cost);
        step2 = cost[idx] + solve(idx + 2, cost);

        return dp[idx] = min(step1, step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return min(solve(0, cost), solve(1, cost));
    }
};