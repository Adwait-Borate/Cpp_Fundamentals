class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& cost) {
        if (i <= 1)
            return cost[i];

        if (dp[i] != -1)
            return dp[i];

        int result = min(solve(i - 1, cost), solve(i - 2, cost)) + cost[i];

        return dp[i] = result;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n, -1);

            return min(solve(n - 1, cost), solve(n - 2, cost));
    }
};
