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
    int mid; //midΪleft��right���е�
    int left=0,right=0;
    for(int i=0;i<woodsLen;i++){
        if(right < woods[i]){
            right = woods[i];
        }
    }
    // printf("right:%d\n",right);
    
    while(left < right){ //��[left,right]��˵��left==right��ζ���ҵ�Ψһλ��
        mid = (left+right) / 2; //ȡ�е�
        if(getCutNum(woods,woodsLen,mid) < K){ //������������һ������������Ԫ�ص�λ��<=mid
            right = mid; //����������[left,mid]����
        }else{ //���������������һ�������������Ԫ�ص�λ��>mid
            left = mid + 1; //��������[mid+1,right]����
        }
        // printf("left:%d,right:%d\n",left,right);
    }

    return left-1; //���ؼг�����λ��
}

int main(){
    int woods[3] = {10,24,15};
    int K = 7;
    int woodsLen = sizeof(woods) / sizeof(woods[0]);
    printf("%d\n",solve(woods,woodsLen,K));

    system("pause");
    return 0;
}