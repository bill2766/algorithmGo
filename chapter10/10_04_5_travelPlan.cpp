#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAXV = 510;
const int INF = 1000000000;

//n 城市数量
//m 道路数量
//st 起点
//des 终点
int n, m, st, des;

//输出：打印路径、距离、花费

int G[MAXV][MAXV];
int Gc[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};
vector<int> pre[MAXV];

void Dijkstra(int s){
    fill(d,d+MAXV, INF);
    d[s] = 0;

    for(int i=0;i<n;i++){
        int u = -1, MIN = INF;
        for(int j=0;j<n;j++){
            if(vis[j] == false && d[j] < MIN){
                MIN = d[j];
                u = j;
            }
        }

        if(u == -1) return;
        vis[u] = true;

        for(int v=0;v<n;v++){
            if(vis[v] == false && G[u][v] != INF){
                if(G[u][v] + d[u] < d[v]){
                    d[v] = G[u][v] + d[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(G[u][v] + d[u] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int optCost = INF;
vector<int> path;
vector<int> tempPath;

void DFS(int v){
    if(v == st){
        int tempCost = 0;
        tempPath.push_back(v);
        for(int i =tempPath.size()-1; i > 0 ;i--){
            int c1 = tempPath[i];
            int c2 = tempPath[i-1];
            tempCost += Gc[c1][c2];
        }
        if(tempCost < optCost){
            optCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}  


int main(){
    fill(G[0],G[0]+ MAXV * MAXV,INF);
    fill(Gc[0],Gc[0]+ MAXV * MAXV,INF);

    scanf("%d%d%d%d",&n,&m,&st,&des);
    int c1,c2;
    int distance,cost;
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&c1,&c2,&distance,&cost);
        G[c1][c2] = distance;
        G[c2][c1] = distance;
        Gc[c1][c2] = cost;
        Gc[c2][c1] = cost;
    }
    Dijkstra(st);
    DFS(des);

    for(int i=path.size()-1; i >= 0;i--){
        printf("%d ",path[i]);
    }
    printf("%d %d\n",d[des],optCost);

    return 0;
}

/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
*/