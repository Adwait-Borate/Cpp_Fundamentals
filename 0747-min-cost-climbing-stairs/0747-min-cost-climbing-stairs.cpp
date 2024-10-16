// class Solution {
// public:
//     int dp[1001];
//     int solve(int idx, vector<int>& cost) {
//         if (idx >= cost.size()) {
//             return 0;
//         }
//         if (dp[idx] != -1) {
//             return dp[idx];
//         }
//         int step1 = 0, step2 = 0;
//         step1 = cost[idx] + solve(idx + 1, cost);
//         step2 = cost[idx] + solve(idx + 2, cost); 

//         return dp[idx] = min(step1, step2);
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         memset(dp, -1, sizeof(dp));
//         return min(solve(0, cost), solve(1, cost));
//     }
// };


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        

        if (n == 1) return cost[0];
        if (n == 2) return min(cost[0], cost[1]);
        
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};
