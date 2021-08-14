
const int MAXN = 1000;
int dp[MAXN];

//斐波那契数列
int F(int n){
    if(n==0 || n==1) return 1;
    else return F(n-1) + F(n-2);
}

int F(int n){
    if(n==0 || n==1) return 1;
    if(dp[n] != -1) return dp[n];
    else{
        dp[n] = F(n-1) + F(n-2);
        return dp[n];
    }
}