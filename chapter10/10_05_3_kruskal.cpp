
/*
struct edge{
    int u,v;
    int cost;
}E[MAXE];

bool cmp(edge a, edge b){
    return a.cost < b.cost;
}

int kruskal(){
    令最小生成树的边权之和为ans、最小生成树的当前边数Num_Edge;
    将所有边按边权从小到大排序;
    for(从小到大枚举所有边){
        if(当前测试边的两个端点在不同的连通块中){
            将该测试边加入最小生成树中;
            ans += 测试边的边权;
            最小生成树的当前边数Num_Edge加1;
            当边数Num_Edge等于顶点数减1时结束循环;
        }
    }
    return ans;
}
*/
#include <algorithm>
using namespace std;

const int MAXE = 1000;

struct edge{
    int u,v;
    int cost;
}E[MAXE];

bool cmp(edge a, edge b){
    return a.cost < b.cost;
}

const int N = 1001;
int father[N];

int findFather(int x){
    while(x != father[x]){
        x = father[x];
    }
    return x;
}

//kruskal函数返回最小生成树的边权之和，参数n为顶点个数，m为图的边数
int kruskal(int n, int m){
    //ans为所求边权之和，Num_Edge为当前生成树的边数
    int ans = 0, Num_Edge = 0;

    for(int i=1; i<=n; i++){ //假设题目中顶点范围是[1,n]
        father[i] = i; //并查集初始化
    }

    sort(E,E+m,cmp);

    for(int i=0; i<m; i++){ //枚举所有边
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if(faU != faV){ //如果不在一个集合中
            father[faU] = faV; //合并集合（即把测试边加入最小生成树中）
            ans += E[i].cost;
            Num_Edge ++;
            if(Num_Edge == n-1) break;
        }
    }
    if(Num_Edge != n-1) return -1;
    else return ans;
}

