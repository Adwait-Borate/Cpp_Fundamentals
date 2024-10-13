// class Solution {
// public:
// bool solve(vector<int>& stones, int i,int k){
//     if(i==n-1){
//         return true;
//     }

//     if(stone[i]+k==stone[i+1]){
//         return true;
//     }else{
//         return false;
//     }

//     for(int i=1;i<n;i++){
//         if(k==stone[i]){
//             return solve(stones,i,k);
//         }
//          if(k-1==stone[i]){
//             return solve(stones,i,k-1);
//         }
//          if(k+1==stone[i]){
//             return solve(stones,i,k+1);
//         }
//     }
// }
//     bool canCross(vector<int>& stones) {
//        return  solve(stones,1,1);
//     }
// };

class Solution {
public:
    int n; 
    vector<vector<int>> dp; 

    bool solve(vector<int>& stones, int i, int k) {
        if (i == n - 1) {
            return true; 
        }

        if (dp[i][k] != -1) {
            return dp[i][k]; 
        }

        for (int jump = k - 1; jump <= k + 1; ++jump) {
            if (jump > 0) { 
                int nextStone = stones[i] + jump;
                

                for (int j = i + 1; j < n; ++j) {
                    if (stones[j] == nextStone) {
                        if (solve(stones, j, jump)) {
                            return dp[i][k] = true;
                        }
                        break; 
                    }
                }
            }
        }

        return dp[i][k] = false;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] != 1) return false; 

        dp = vector<vector<int>>(n, vector<int>(n, -1));

        return solve(stones, 1, 1); 
    }
};
