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
    //设置随机种子
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++){
        //生成一个随机数
        printf("%d ",rand());

        //输入[a,b]范围的随机数：rand() % (b-a+1) + a
        //生成[0,1]的随机数
        printf("%d ",rand() % 2);
        //生成[3,7]的随机数
        printf("%d ",rand() % 5 + 3);

        //先获得浮点数，通过1.0*rand()/RAND_MAX获得“比例”，再获得想要的数范围
        //生成大范围的随机数,[10000,60000]
        printf("%d ",(int)(round(1.0*rand()/RAND_MAX * 50000 + 10000)));
    }

    system("pause");
}

//----------------------------------------------------------------
// using namespace std;

// int randPartition(int A[],int left,int right){
//     int p = (round(1.0*rand()/RAND_MAX * (right-left) + left));
//     swap(A[p],A[left]);
//     int temp = A[left];
//     while(left < right){
//         while(left<right && A[right]>temp) right--;
//         A[left] = A[right];
//         while(left<right && A[left]<temp) left++;
//         A[right] = A[left];
//     }
//     A[left] = temp;
//     return left;
// }