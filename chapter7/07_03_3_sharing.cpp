#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 100010;
struct NODE{
    char data;
    bool flag;
    int next; //存放下一个节点的地址
}node[maxn];

int main(){
    for(int i=0;i<maxn;i++){
        node[i].flag = false;
    }
    //读1
    int b1,b2,num;
    scanf("%d%d%d",&b1,&b2,&num);
    //读2
    int theAdd,destAdd;
    char ch;
    //建立链表
    for(int i=0;i<num;i++){
        scanf("%d %c %d",&theAdd,&ch,&destAdd);
        node[theAdd].data = ch;
        node[theAdd].next = destAdd;
    }
    int p;
    for(p=b1;p!=-1;p = node[p].next){
        node[p].flag = true;
    }
    for(p=b2;p!=-1;p = node[p].next){
        if(node[p].flag == true){
            break;
        }
    }
    if(p != -1){
        printf("%05d\n",p);
    }else{
        printf("-1\n");
    }
    
    system("pause");
    return 0;
}