#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

const int MAXV = 510;
const int INF = 1000000000;

struct Node{
    int v, dis;
    Node(int _v,int _dis) : v(_v),dis(_dis) {}
};
vector<Node> Adj[MAXV];

//n 城市数量
//m 道路数量
//st 起点
//des 终点
int n, m, st, des;
int weight[MAXV];

int d[MAXV],w[MAXV],num[MAXV]; //最短距离；最大点权之和；最短路径条数
set<int> pre[MAXV];


void Bellman(int s){
    fill(d,d+MAXV,INF);
    memset(num,0,sizeof(num));
    memset(w,0,sizeof(w));

    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;

    for(int i=0;i<n-1;i++){
        for(int u=0;u<n;u++){
            for(int j=0;j<Adj[u].size();j++){
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;

                if(d[u] + dis < d[v]){
                    d[v] = d[u] + dis;
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                }else if(d[u] + dis == d[v]){
                    if(w[u] + weight[v] > w[v]){
                        w[v] = w[u] + weight[v];
                    }
                    pre[v].insert(u);
                    num[v] = 0;
                    set<int>::iterator it;
                    for(it = pre[v].begin();it!=pre[v].end();it++){
                        num[v] += num[*it];
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d",&n,&m,&st,&des);
    for(int i=0;i<n;i++){
        scanf("%d",&weight[i]);
    }

    int c1,c2;
    int wt;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&c1,&c2,&wt);
        Adj[c1].push_back(Node(c2,wt));
        Adj[c2].push_back(Node(c1,wt));
    }
    Bellman(st);
    printf("%d %d\n",num[des],w[des]);
    return 0;
}

/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/

//2 4