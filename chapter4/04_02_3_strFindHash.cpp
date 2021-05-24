#include <cstdio>
#include <stdlib.h>

const int maxn = 100;
char S[maxn][5],temp[5];
int hashTable[26*26*26+10] = {0};

int hashFunc(char S[],int len){
    int id = 0;
    for(int i=0;i<len;i++){
        id = id*26 + (S[i] - 'A');
    };
    return id;
}

int main(){
    //m是否在n出现过
    int n,m;
    scanf("%d%d",&n,&m);
    printf("n m: %d %d\n",n,m);
    for(int i=0;i<n;i++){
        scanf("%s",S[i]);
        printf("input one value\n");
        int index = hashFunc(S[i],3);
        hashTable[index]++;
    }
    for(int i=0;i<m;i++){
        scanf("%s",temp);
        int index = hashFunc(temp,3);
        printf("%d\n",hashTable[index]);
    }

    system("pause");
    return 0;
}