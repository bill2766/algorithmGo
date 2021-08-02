#include <vector>
using namespace std;

//实现伪代码
/*
DFS(u){
    vis[u] = true;
    for(从u出发能到达的所有顶点v){
        if(vis[v] == false){
            DFS(v);
        }
    }
}

DFSTrave(G){
    for(G的所有顶点u){
        if(vis[u] == false){
            DFS(u);
        }
    }
}
*/

const int MAXV = 1000; //最大顶点数
const int INF = 1000000000; //无穷大的数

int n,G[MAXV][MAXV];
bool vis[MAXV] = {false};

//邻接矩阵版本
void DFS(int u, int depth){
    vis[u] = true;
    //这里写对u操作的代码
    for(int v=0;v<n;v++){
        if(vis[v] == false && G[u][v] != INF){
            DFS(v,depth+1);
        }
    }
}

void DFSTrave(){
    for(int u=0;u<n;u++){
        if(vis[u] == false){
            DFS(u,1);
        }
    }
}

//邻接表版本
vector<int> Adj[MAXV]; //图G的邻接表
int n; //n为顶点数，MAXV为最大顶点数
bool vis[MAXV] = {false};

void DFS(int u, int depth){
    vis[u] = true;
    //这里可以对u进行操作
    for(int i=0;i<Adj[u].size();i++){
        int v = Adj[u][i];
        if(vis[v] == false){
            DFS(v,depth+1);
        }
    }
}

void DFSTrave(){
    for(int u=0;u<n;u++){
        if(vis[u] == false){
            DFS(u,1);
        }
    }
}