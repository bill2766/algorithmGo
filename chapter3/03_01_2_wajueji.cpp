#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(){
    int number = 0;
    scanf("%d",&number);
    int schools[number] = {0};
    int peoIn,peoScore;
    for (int i=0;i<number;i++){
        scanf("%d %d",&peoIn,&peoScore);
        schools[peoIn-1] += peoScore;
        //printf("%d:%d\n",peoIn,schools[peoIn-1]);
    }
    int maxPeoIn = 1;
    int maxPeoScore = schools[maxPeoIn-1];
    for(int i=0;i<number;i++){
        if(schools[i] >= maxPeoScore){
            maxPeoIn = i+1;
            maxPeoScore = schools[i];
        }
    }
    printf("%d %d\n",maxPeoIn,maxPeoScore);
    

    system("pause");
    return 0;
}