class Solution {
public:
int dp[38];
int solve(int n){
    if(n==0){
        return 0;
    }
    
    if(dp[n]!=-1){
        return dp[n];
    }
    if(n==1 || n==2){
        return 1;
    }

    return dp[n]=solve(n-3)+solve(n-2)+solve(n-1);
}
    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};