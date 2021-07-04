#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 100010;
struct NODE{
    char data;
    bool flag;
    int next; //�����һ���ڵ�ĵ�ַ
}node[maxn];

int main(){
    for(int i=0;i<maxn;i++){
        node[i].flag = false;
    }
    //��1
    int b1,b2,num;
    scanf("%d%d%d",&b1,&b2,&num);
    //��2
    int theAdd,destAdd;
    char ch;
    //��������
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