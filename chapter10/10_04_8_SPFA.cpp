//SPFA 核心代码
/*
queue<int> Q;
源点s入队;
while(队列非空){
    取出队首元素u;
    for(u的所有邻接边u->v){
        if(d[u] + dis < d[v]){
            d[v] = d[u] + dis;
            if(v当前不在队列){
                v入队;
                if(v入队次数大于n-1){
                    说明有可达负环，return;
                }
            }
        }
    }
}
*/

#include <vector>
#include <queue>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3fffffff;

struct Node{
    int v, dis;
    Node(int _v,int _dis) : v(_v),dis(_dis) {}
};
vector<Node> Adj[MAXV]; //图G的邻接表
int n, d[MAXV], num[MAXV]; //num数组记录顶点的入队次数
bool inq[MAXV]; //顶点是否在队列中

bool SPFA(int s){
    memset(inq,false,sizeof(inq));
    memset(num,0,sizeof(num));
    fill(d, d+MAXV, INF);

    queue<int> Q;
    
    Q.push(s);
    inq[s] = true;
    num[s]++;
    d[s] = 0;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        inq[u] = false;

        for(int j=0;j<Adj[u].size();j++){
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;

            if(d[u] + dis < d[v]){
                d[v] = d[u] + dis;
                if(!inq[v]){
                    Q.push(v);
                    inq[v] = true;
                    num[v]++;
                    if(num[v] >= n) return false;
                }
            }
        }
    }
    return true;
}