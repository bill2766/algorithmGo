int Partition(int A[],int left,int right){
    int temp = A[left];
    while(left < right){
        while(left<right && A[right]>temp) right--;
        A[left] = A[right];
        while(left<right && A[left]<temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void quickSort(int A[],int left,int right){
    if(left < right){
        int pos = Partition(A,left,right);
        quickSort(A,left,pos-1);
        quickSort(A,pos+1,right);
    }
}


//----------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    //�����������
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++){
        //����һ�������
        printf("%d ",rand());

        //����[a,b]��Χ���������rand() % (b-a+1) + a
        //����[0,1]�������
        printf("%d ",rand() % 2);
        //����[3,7]�������
        printf("%d ",rand() % 5 + 3);

        //�Ȼ�ø�������ͨ��1.0*rand()/RAND_MAX��á����������ٻ����Ҫ������Χ
        //���ɴ�Χ�������,[10000,60000]
        printf("%d ",(int)(round(1.0*rand()/RAND_MAX * 50000 + 10000)));
    }

    system("pause");
}

//----------------------------------------------------------------
using namespace std;

int randPartition(int A[],int left,int right){
    int p = (round(1.0*rand()/RAND_MAX * (right-left) + left));
    swap(A[p],A[left]);
    int temp = A[left];
    while(left < right){
        while(left<right && A[right]>temp) right--;
        A[left] = A[right];
        while(left<right && A[left]<temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}