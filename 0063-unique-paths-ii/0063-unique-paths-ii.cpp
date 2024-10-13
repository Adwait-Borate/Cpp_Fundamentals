class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, int r, int l) {
        if (i >= r || j >= l || i < 0 || j < 0 || obstacleGrid[i][j] == 1) {
            return 0;
        }

        if (i == r - 1 && j == l - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, obstacleGrid, r, l);
        int down = solve(i + 1, j, obstacleGrid, r, l);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        int r = obstacleGrid.size();
        int l = obstacleGrid[0].size();

        return solve(0, 0, obstacleGrid, r, l);
    }
};
