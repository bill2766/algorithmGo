#include <queue>
using namespace std;

//实现伪代码
/*
BFS(u){
    queue q;
    将u入队;
    inq[u] = true;
    while(q非空){
        取出q的队首元素进行访问;
        for(从u出发可达的所有顶点v){
            if(inq[v] == false){
                将v入队;
                inq[v] = true;
            }
        }
    }
}

BFSTrave(G){
    for(G的所有顶点u){
        if(inq[u] == false){
            BFS(u);
        }
    }
}
*/

const int MAXV = 1000; //最大顶点数
const int INF = 1000000000; //无穷大的数

/*
//邻接矩阵版本
int n,G[MAXV][MAXV];
bool inq[MAXV] = {false};

void BFS(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0;v<n;v++){
            if(G[u][v] != INF && inq[v] == false){
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

void BFSTrave(){
    for(int u=0;u<n;u++){
        if(inq[u] == false){
            BFS(u);
        }
    }
}

//邻接表版本
vector<int> Adj[MAXV];
int n;
bool inq[MAXV] = {false};

void BFS(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<Adj[u].size();i++){
            int v = Adj[u][i];
            if(inq[v] == false){
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

void BFSTrave(){
    for(int u=0;u<n;u++){
        if(inq[u] == false){
            BFS(u);
        }
    }
}
*/

//加层号
struct Node{
    int v;
    int layer;
};

vector<Node> Adj[MAXV];
bool inq[MAXV] = {false};

void BFS(int s){
    queue<Node> q;
    Node start;
    start.v = s;
    start.layer = 0;
    q.push(start);
    inq[start.v] = true;
    while(!q.empty()){
        Node topNode = q.front();
        q.pop();
        int u = topNode.v;
        for(int i=0;i<Adj[u].size();i++){
            Node next = Adj[u][i];
            next.layer = topNode.layer+1;
            if(inq[next.v] == false){
                q.push(next);
                inq[next.v] = true;
            }
        }
    }
}