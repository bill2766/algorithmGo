#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 1000; //最大顶点数
const int INF = 1000000000; //设INF为一个很大的数

int n, m, s, G[MAXV][MAXV]; //n为顶点数，m为边数，s为起点
int d[MAXV]; //起点到达各点的最短路径长度
bool vis[MAXV] = {false}; //true表示已访问

void Dijkstra(int s){ //s为起点
    fill(d,d+MAXV,INF);
    d[s] = 0;
    for(int i=0;i<n;i++){
        int u=-1, MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return;
        vis[u] = true;

        for(int v=0;v<n;v++){
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main(){
    int u, v, w;
    scanf("%d%d%d",&n,&m,&s); //顶点个数、边数、起点编号
    fill(G[0],G[0]+ MAXV * MAXV,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        G[u][v] = w;
    }
    Dijkstra(s);
    for(int i=0; i<n; i++){
        printf("%d ",d[i]);
    }

    return 0;
}



//--------------------------------------------------------------------
int pre[MAXV]; //从起点到顶点v的路径上v的前一个顶点

void Dijkstra(int s){ //s为起点
    fill(d,d+MAXV,INF);
    for(int i=0;i<n;i++) pre[i] = i; //初始状态设每个点的前驱为自身
    d[s] = 0;
    for(int i=0;i<n;i++){
        int u=-1, MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return;
        vis[u] = true;

        for(int v=0;v<n;v++){
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
                pre[v] = u;
            }
        }
    }
}

void DFS(int s, int v){
    if(v == s){
        printf("%d\n", s);
        return;
    }
    DFS(s,pre[v]);
    printf("%d\n",v);
}