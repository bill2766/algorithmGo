#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

int n,m;

int G[MAXV][MAXV];
int d[MAXV];
int vis[MAXV] = {false};

int prim(){
    fill(d,d+MAXV,INF);

    d[0] = 0;
    int ans = 0; //存放最小生成树的边权之和

    for(int i=0;i<n;i++){
        int u=-1, MIN=INF;
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return -1;
        vis[u] = true;
        ans += d[u];

        for(int v=0;v<n;v++){
            if(vis[v] == false && G[u][v] != INF && G[u][v] < d[v]){
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

int main(){
    fill(G[0],G[0]+MAXV*MAXV,INF);

    scanf("%d%d",&n,&m);
    int from,to, w;
    for(int i=0; i<m; i++){
        scanf("%d%d%d",&from,&to,&w);
        G[from][to] = G[to][from] = w;
    }
    int ans = prim();
    printf("%d\n",ans);

    return 0;
}

/*
6 10
0 1 4
0 4 1
0 5 2
1 2 6
1 5 3
2 3 6
2 5 5
3 4 4
3 5 5
4 5 3
*/

//15