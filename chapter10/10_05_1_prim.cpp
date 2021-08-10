//prim算法核心伪代码
/*
//G为图，一般设成全局变量；数组d为顶点与集合S的最短距离
Prim(G,d[]){
    初始化;
    for(循环n次){
        u =  使d[u]最小的还未被访问的顶点的标号;
        记u已被访问;
        for(从u出发能到达的所有顶点v){
            if(v未被访问 && 以u为中介点使得v与集合S的最短距离d[v]更优){
                将G[u][v]赋值给v与集合S的最短距离d[v];
            }
        }
    }
}
*/

#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 1000; //最大顶点数
const int INF = 1000000000; //设INF为一个很大的数

//邻接矩阵版本
int n, G[MAXV][MAXV]; //n为顶点数
int d[MAXV]; //顶点与集合S的最短距离
bool vis[MAXV] = {false}; //标记数组，vis[i]==true表示已访问。初值均为false

int prim(){ //默认0号为初始点，函数返回最小生成树的边权之和
    fill(d,d+MAXV,INF);
    d[0] = 0;
    int ans = 0;

    for(int i=0; i<n; i++){
        int u=-1, MIN=INF;
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return -1;
        vis[u] = true;
        ans+= d[u];

        for(int v=0; v<n; v++){
            if(vis[v]==false && G[u][v] != INF && G[u][v] < d[v]){
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

//邻接表版本
struct Node{
    int v, dis; //v为边的目标顶点，dis为边权
};
vector<Node> Adj[MAXV];
int n;
int d[MAXV];
bool vis[MAXV] = {false};

int prim(){
    fill(d,d+MAXV,INF);
    d[0] = 0; //只有0号顶点到集合S的距离为0，其余全为INF
    int ans = 0;

    for(int i=0; i<n; i++){
        int u=-1, MIN=INF;
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j]<MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return -1;
        vis[u] = true;
        ans += d[u];

        for(int j=0;j<Adj[u].size(); j++){
            int v = Adj[u][v].v;
            if(vis[v] == false && Adj[u][j].dis < d[v]){
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}