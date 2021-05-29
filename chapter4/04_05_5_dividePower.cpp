#include <cstdio>
#include <stdlib.h>
#include <cmath>
using namespace std;

// int getPower(int a,int b){
//     if(b==0){
//         return 1;
//     }
//     if(b%2 == 0){
//         int num = getPower(a,b/2);
//         return num * num;
//     }else{
//         return a * getPower(a,b-1);
//     }
// }

typedef long long LL;

LL binaryPow(LL a,LL b,LL m){
    if(b==0){
        return 1;
    }
    if(b % 2 == 0){
        LL mul = binaryPow(a,b/2,m);
        return mul * mul % m;
    }else{
        return a * binaryPow(a,b-1,m) % m;
    }
}

LL binaryPow2(LL a,LL b,LL m){
    LL ans = 1;
    while(b > 0){
        if(b & 1){
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main(){
    LL result = binaryPow2(2,5,100);
    printf("result:%d\n",result);

    system("pause");
    return 0;
}

