#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXV = 510;
const int INF = 1000000000;

int N, M, C1, C2;

int G[MAXV][MAXV];
int weight[MAXV];

int d[MAXV];
int addW[MAXV];
int way[MAXV];

bool vis[MAXV] = {false};

void Dijkstra(int C1){
    fill(d,d + MAXV,INF);
    memset(way,0,sizeof(way));
    memset(addW,0,sizeof(addW));

    addW[C1] = weight[C1];
    way[C1] = 1;
    d[C1] = 0;

    for(int i=0;i<N;i++){
        int v = -1, MIN = INF;
        for(int j=0;j<N;j++){
            if(vis[j] == false && d[j] < MIN){
                v = j;
                MIN = d[j];
            }
        }

        if(v == -1) return;
        vis[v] = true;

        for(int j=0;j<N;j++){
            if(vis[j] == false && G[v][j] != INF){
                if(d[v] + G[v][j] < d[j]){
                    d[j] = d[v] + G[v][j];
                    addW[j] = addW[v] + weight[j];
                    way[j] = way[v];
                }else if(d[v] + G[v][j] == d[j]){
                    way[j] += way[v];
                    if(addW[v] + weight[j] > addW[j]){
                        addW[j] = addW[v] + weight[j];
                    }
                }
            }
        }
    }
}


int main(){

    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i=0;i<N;i++){
        scanf("%d",&weight[i]);
    }

    int from,to;
    fill(G[0],G[0]+ MAXV * MAXV,INF);
    for(int i=0;i<M;i++){
        scanf("%d%d",&from,&to);
        scanf("%d",&G[from][to]);
    }
    Dijkstra(C1);

    printf("%d %d",way[C2],addW[C2]);
    return 0;
}