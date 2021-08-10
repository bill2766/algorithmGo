//Floyd核心伪代码
/*
枚举顶点k ∈ [1,n]
    以顶点k作为中介点，枚举所有顶点对i和j（i ∈ [1,n], j ∈ [1,n]）
        如果dis[i][k] + dis[k][j] < dis[i][j]成立
            赋值dis[i][j] = dis[i][k] + dis[k][j]
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
const int MAXV = 200; //MAXV为最大顶点数

int n, m; //n为顶点数，m为边数
int dis[MAXV][MAXV]; //dis[i][j]表示顶点i和顶点j的最短距离

void Floyd(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main(){
    int u, v, w;
    fill(dis[0],dis[0]+MAXV * MAXV, INF);
    scanf("%d%d",&n,&m); //顶点数n、边数m
    for(int i=0; i<n; i++){
        dis[i][i] = 0;
    }
    
    for(int i=0;i<m; i++){
        scanf("%d%d%d",&u,&v,&w);
        dis[u][v] = w;
    }
    Floyd();
    
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            printf("%d ",dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
6 8
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3
*/