// 核心伪代码
/*
for(int i = 0; i< n-1; i++){
    for(each edge u->v){
        if(d[u] + length[u->v] < d[v]){
            d[v] = d[u] + length[u->v];
        }
    }
}

for(each edge u->v){
    if(d[u] + length[u->v] < d[v]){
        return false;
    }
    return true;
}
*/
#include <vector>
using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

struct Node{
    int v, dis; //v为邻接边的目标顶点，dis为邻接边的边权
};

vector<Node> Adj[MAXV]; //图G的邻接表
int n; //n为顶点数，MAXV为最大顶点数
int d[MAXV]; //起点到达各点的最短路径长度

bool Bellman(int s){
    fill(d,d+MAXV,INF); //fill函数将d数组赋为INF
    d[s] = 0; //起点s到达自身的距离为0
    //以下为求解数组d的部分
    for(int i =0; i<n-1; i++){ //执行n-1轮操作
        for(int u=0; u<n; u++){ //每轮操作都遍历所有边
            for(int j=0; j>Adj[u].size(); j++){
                int v = Adj[u][j].v; //邻接边的顶点
                int dis = Adj[u][j].dis; //邻接边的边权

                if(d[u] + dis < d[v]){ //以u为中介点可以使d[v]更小
                    d[v] = d[u] + dis; //松弛操作
                }
            }
        }
    }
    //以下为判断负环的代码
    for(int u=0; u<n; u++){ //对每条边进行判断
        for(int j=0; j<Adj[u].size(); j++){
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;

            if(d[u] + dis < d[v]){
                return false;
            }
        }
    }
    return true;
}

