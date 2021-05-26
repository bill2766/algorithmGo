#include <cstdio>
#include <stdlib.h>
const int maxn=11;

int n,P[maxn],hashTable[maxn] = {false};
int count=0;

void generateP(int index){
    if(index == n+1){
        count++;
        return;
    }

    for(int x=1;x<=n;x++){
        //全排列+判断不在一条直线上
        if(hashTable[x]==false){
            bool flag=true;
            for(int pre=1;pre<index;pre++){
                if(abs(index-pre) == abs(x-P[pre])){
                    flag=false;
                    break;
                }
            }
            //不能放置就直接忽略这个情况
            if(flag){
                P[index]=x;
                hashTable[index] = true;
                generateP(index+1);
                hashTable[index] = false;
            }
        }
    }
}

int main(){

    system("pause");
    return 0;
}