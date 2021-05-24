#include <cstdio>
#include <stdlib.h>

using namespace std;


int main(){
    int A,B;
    int base;

    scanf("%d %d %d",&A,&B,&base);
    int resultTen = A+B;

    int result[31];
    int num=0;
    do{
        result[num] = resultTen % base;
        num++;
        resultTen = resultTen / base;
        // printf("%d",resultTen);
    }while(resultTen != 0);

    for(int i=num-1;i>=0;i--){
        printf("%d",result[i]);
    }

    system("pause");
    return 0;
}