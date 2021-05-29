#include <cstdio>
#include <stdlib.h>
#include <cmath>
using namespace std;

int getCutNum(int woods[],int woodsLen,int l){
    int k=0;
    for(int i=0;i<woodsLen;i++){
        k+= woods[i]/l;
    }
    // printf("k:%d\n",k);
    return k;
}

int solve(int woods[],int woodsLen,int K){
    int mid; //mid为left和right的中点
    int left=0,right=0;
    for(int i=0;i<woodsLen;i++){
        if(right < woods[i]){
            right = woods[i];
        }
    }
    // printf("right:%d\n",right);
    
    while(left < right){ //对[left,right]来说，left==right意味着找到唯一位置
        mid = (left+right) / 2; //取中点
        if(getCutNum(woods,woodsLen,mid) < K){ //条件成立，第一个满足条件的元素的位置<=mid
            right = mid; //往左子区间[left,mid]查找
        }else{ //条件不成立，则第一个满足该条件的元素的位置>mid
            left = mid + 1; //往右区间[mid+1,right]查找
        }
        // printf("left:%d,right:%d\n",left,right);
    }

    return left-1; //返回夹出来的位置
}

int main(){
    int woods[3] = {10,24,15};
    int K = 7;
    int woodsLen = sizeof(woods) / sizeof(woods[0]);
    printf("%d\n",solve(woods,woodsLen,K));

    system("pause");
    return 0;
}