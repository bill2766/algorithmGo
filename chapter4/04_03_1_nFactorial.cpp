#include <cstdio>
#include <stdlib.h>

int F(int n){
    if(n!=0){
        return F(n-1)*n;
    }else{
        return 1;
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