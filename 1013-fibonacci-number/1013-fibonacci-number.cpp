class Solution {
public:
int dp[31];
int solve(int n){
    if(n==0 ){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(dp[n]!=-1){
     return dp[n];
    }
    dp[n]=solve(n-1)+solve(n-2);
    return dp[n];
}
    int fib(int n) {
        memset(dp,-1,sizeof(dp));
       return  solve(n);
    }
};