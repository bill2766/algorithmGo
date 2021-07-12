#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 100005;
struct NODE{
    int address;
    int data;
    bool flag;
    int next;
}node[maxn];

bool cmp(NODE a,NODE b){
    if(a.flag==false || b.flag==false){
        return a.flag > b.flag;
    }else{
        return a.data<b.data;
    }
}

int main(){
    for(int i=0;i<maxn;i++){
        node[i].flag = false;
    }
    //读1
    int num,begin;
    scanf("%d%d",&num,&begin);
    //读2
    int address;
    //建立链表
    for(int i=0;i<num;i++){
        scanf("%d",&address);
        scanf("%d%d",&node[address].data,&node[address].next);
        node[address].address = address;
    }
    int count = 0;
    int p = begin;
    while(p!=-1){
        node[p].flag = true;
        count++;
        p=node[p].next;
    }
    if(count == 0){
        printf("0 -1");
    }else{
        //排序
        sort(node,node+maxn,cmp);
        //打印
        printf("%d %05d\n",count,node[0].address);
        for(int i=0;i<count;i++){
            if(i != count -1){
                printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
            }else{
                printf("%05d %d -1\n",node[i].address,node[i].data);
            }
        }
    }
    
    
    
    system("pause");
    return 0;
}