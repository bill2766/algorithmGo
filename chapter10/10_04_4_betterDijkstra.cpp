#include <vector>
#include <algorithm>
using namespace std;

int n,m;

const int MAXV = 1000;
const int INF = 1000000000;

int G[MAXV][MAXV];
vector<int> pre[MAXV];
int d[MAXV];
bool vis[MAXV];
vector<int> pre[MAXV];

void Dijkstra(int s){
    fill(d, d+MAXV, INF);
    d[s] = 0;

    for(int i=0;i<n;i++){
        int u=-1, MIN = INF; //找到最小的d[u]
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return;
        vis[u] = true;

        for(int v=0; v<n; v++){
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

