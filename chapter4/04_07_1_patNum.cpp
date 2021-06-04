#include <cstdio>
#include <stdlib.h>
#include <string.h>

using namespace std;

void getP(char* str,int strLen,int* Pnums){
    if(str[0] == 'P'){
        Pnums[0] = 1;
    }else{
        Pnums[0] = 0;
    }
    for(int i=1;i<strLen;i++){
        if(str[i] == 'P'){
            Pnums[i] = Pnums[i-1] + 1;
        }else{
            Pnums[i] = Pnums[i-1];
        }
    }
}

void getT(char* str,int strLen,int* Tnums){
    if(str[strLen - 1] == 'T'){
        Tnums[strLen-1] = 1;
    }else{
        Tnums[strLen-1] = 0;
    }
    for(int i=strLen-2;i>=0;i--){
        if(str[i] == 'T'){
            Tnums[i] = Tnums[i+1] + 1;
        }else{
            Tnums[i] = Tnums[i+1];
        }
    }
}

int getPatNum(char* str,int strLen){
    int sum = 0;
    int Pnums[strLen] = {0};
    getP(str,strLen,Pnums);
    for(int i=0;i<strLen;i++){
        printf("%d ",Pnums[i]);
    }
    printf("\n");

    int Tnums[strLen] = {0};
    getT(str,strLen,Tnums);
    for(int i=0;i<strLen;i++){
        printf("%d ",Tnums[i]);
    }
    printf("\n");

    for(int i=0;i<strLen;i++){
        if(str[i]== 'A'){
            sum+= Pnums[i] * Tnums[i];
        }
    }
    return sum;
}

// int main(){
//     char str[] = "APPAPT";
//     int strLen = 6;
//     int patNum = getPatNum(str,strLen);
//     printf("%d ",patNum%1000000007);

//     system("pause");
//     return 0;
// }

//----------------------------------------------------------
#include <cstdio>
#include <cstring>

const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN];
int leftNumP[MAXN] = {0};
int main(){
    //获得一串字符串
    gets(str);
    // printf("%s\n",str);
    //获得数组长度
    int len= strlen(str);
    for(int i=0;i<len;i++){
        if(i>0){
            leftNumP[i] = leftNumP[i-1];
        }
        if(str[i] == 'P'){
            leftNumP[i]++;
        }
    }
    int ans=0,rightNumT =0;
    for(int i=len-1;i>=0;i--){
        if(str[i] == 'T'){
            rightNumT++;
        }else if(str[i] == 'A'){
            ans = (ans + leftNumP[i] * rightNumT) % MOD;
        }
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}