/*
#include <vector>
using namespace std;

struct node{
    typename data;
    vector child;
}Node[maxn];

int index = 0;
int newNode(int v){
    Node[index].data = v;
    Node[index].child.clear();
    return index++;
}

// vector<int> child[maxn];

void PreOrder(int root){
    printf("%d ",Node[root].data);
    for(int i=0;i< Node[root].child.size();i++){
        PreOrder(Node[root].child[i]);
    }
}

void LayerOrder(int root){
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int front = Q.front();
        printf("%d ",Node[front].data);
        Q.pop();
        for(int i=0;i<Node[front].child.size();i++){
            Q.push(Node[front].child[i]);
        }
    }
}
*/

/*
struct node{
    int layer;
    int data;
    vector<int> child;   
};

void LayerOrder(int root){
    queue<int> Q;
    Q.push(root);
    Node[root].layer = 0;
    while(!Q.empty()){
        int front = Q.front();
        printf("%d ",Node[front].data);
        Q.pop();
        for(int i=0;i<Node[front].child.size();i++){
            int child = Node[front].child[i];
            Node[child].layer = Node[front].layer+1;
            Q.push(child);
        }
    }
}
*/

