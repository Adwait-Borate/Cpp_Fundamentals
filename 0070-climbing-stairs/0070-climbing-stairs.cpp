class Solution {
public:
int dp[46];
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));

        //base case
        dp[0]=1;
        dp[1]=1;

       //transition 
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
       //final result
        return dp[n];
    }
};