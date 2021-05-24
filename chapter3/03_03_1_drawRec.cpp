#include <cstdio>
#include <stdlib.h>

using namespace std;


int main(){
    int chang,kuan;
    char c;

    scanf("%d %c",&chang,&c);
    if(chang%2 == 1){
        kuan = chang/2+1;
    }else{
        kuan = chang/2;
    }

    for(int i=0;i<chang;i++){
        printf("%c",c);
    }
    printf("\n");
    
    for(int i=2;i<kuan;i++){
        printf("%c",c);
        for(int j=0;j<chang-2;j++){
            printf(" ");
        }
        printf("%c\n",c);
    }

    for(int i=0;i<chang;i++){
        printf("%c",c);
    }

    system("pause");
    return 0;
}