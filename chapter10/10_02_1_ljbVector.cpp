#include <vector>
using namespace std;

struct Node{
    int v; //边的终点编号
    int w; //边权
    //构造函数
    Node(int _v,int _w) : v(_v),w(_w) {}
};

int main(){
    const int N = 100;
    // vector<int> Adj[N];

    // Adj[1].push_back(3);

    //--------------------------

    vector<Node> Adj[N];

    // Node temp;
    // temp.v = 3;
    // temp.w = 4;
    // Adj[1].push_back(temp);

    Adj[1].push_back(Node(3,4));
}

