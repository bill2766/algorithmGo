#include <cstdio>
#include <stdlib.h>
#include <string.h>

using namespace std;


int main(){
    char str[255];
    scanf("%s",str);

    int strLen = strlen(str);
    int half;
    if(strLen / 2 == 0){
        //偶数
        half = strLen / 2;
    }else{
        half = (strLen+1) / 2;
    }

    for(int i=0;i<half;i++){
        if(str[i] != str[strLen-1-i]){
            printf("NO");
            system("pause");
            return 0;
        }
    }
    printf("YES");
    system("pause");
    return 0;
}