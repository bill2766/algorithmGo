#include <vector>
#include <queue>
using namespace std;

const int MAXV = 1000;

vector<int> G[MAXV]; //邻接表
int n, m, inDegree[MAXV]; //顶点数、入度
//拓扑排序
int topologicalSort(){
    int num = 0; //记录加入拓扑序列的顶点数
    queue<int> q;

    for(int i=0; i<n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front(); //取队首顶点u
        //printf("%d",u); //此处可输出顶点u，作为拓扑序列中的顶点
        q.pop();
        
        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i]; //u的后继结点v
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
        G[u].clear(); //清空顶点u的所有出边（如无必要可不写）
        num++; //加入拓扑序列的顶点数加1
    }
    if(num == n) return true; //加入拓扑序列的顶点数为n，说明拓扑排序成功
    else return false;
}
