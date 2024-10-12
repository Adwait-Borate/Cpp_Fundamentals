class Solution {
public:
vector<vector<int>>dp;
    int solve(int i, int j, vector<vector<int>>& triangle) {
        if(i == triangle.size() - 1) {
            return triangle[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = solve(i + 1, j, triangle); 
        int diagonal = solve(i + 1, j + 1, triangle);  

        return dp[i][j]=triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        dp.resize(n, vector<int>(n, -1)); 
        return solve(0, 0, triangle);
    }
};
