#include <cstdio>
#include <stdlib.h>

int F(int n){
    if(n==0 || n==1){
        return 1;
    }else{
        return F(n-1)+F(n-2);
    }
}

int main(){
    int value;
    int result;
    scanf("%d",&value);

    result = F(value);
    printf("%d\n",result);

    system("pause");
    return 0;
}