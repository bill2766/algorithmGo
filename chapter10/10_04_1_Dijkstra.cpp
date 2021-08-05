#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//伪代码
/*
Dijkstra(G,d[],s){
    初始化;
    for(循环n次){
        u = 使d[u]最小的还未被访问的顶点的标号;
        记u已被访问;
        for(从u出发能到达的所有顶点v){
            if(v未被访问 && 以u为中介点使s到顶点v的最短距离d[v]更优){
                优化d[v];
            }
        }
    }
}
*/

const int MAXV = 1000;
const int INF = 1000000000;

//邻接矩阵版本
int n,G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s){
    fill(d,d+MAXV,INF);
    d[s] = 0;
    for(int i=0;i<n;i++){
        int u = -1, MIN = INF;
        for(int j=0;j<n;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return;
        vis[u] = true;

        for(int v=0;v < n; v++){
            if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
            }
        }
    }
}


//邻接表版本
struct Node{
    int v, dis; //v为边的目标顶点，dis为边权
};

vector<Node> Adj[MAXV];
int n;
int d[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s){
    fill(d,d+MAXV,INF);
    d[s] = 0;
    for(int i=0;i<n;i++){
        int u= -1, MIN = INF;
        if(vis[u] == false && d[u] < MIN){
            u = i;
            MIN = d[u];
        }

        if(u == -1) return;
        vis[u] = true;

        for(int j=0;j<Adj[u].size();j++){
            int v = Adj[i][j].v;
            if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]){
                d[v] = d[u] + Adj[u][j].dis;
            }
        }
    }

}

