
/*
int DP(int i){
    if(dp[i] > 0) return dp[i]; //dp[i]已计算得到
    for(int j=0; j<n; j++){ //遍历i的所有出边
        //一直往外延伸，直到终点
        if(G[i][j] != INF){
            int temp = DP(j) + G[i][j];
            if(temp > dp[i]){
                dp[i] = temp;
                choice[i] = j;
            }
        }
    }
    return dp[i];
}

//调用printPath前需要先得到最大的dp[i]，然后将i作为路径起点传入
void printPath(int i){
    printf("%d",i);
    while(choice[i] != -1){
        i = choice[i];
        printf("->%d",i);
    }
}
*/

/*
//固定终点，求DAG的最长路径长度
int DP(int i){
    if(vis[i]) return dp[i];
    vis[i] = true;
    for(int j=0; j<n; j++){
        if(G[i][j] != INF){
            dp[i] = max(dp[i],DP(j) + G[i][j]);
        }
    }
    return dp[i];
}
*/