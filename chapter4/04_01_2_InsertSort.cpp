#include <cstdio>
#include <stdlib.h>

using namespace std;

const int maxn = 100;
int A[maxn],n;

void insertSort(){
    for(int i=2;i<=n;i++){
        int temp=A[i],j=i;
        while(j>1 && temp < A[j-1]){
            A[j] = A[j-1];
            j--;
        }
        A[j] = temp;
    }
}

int main(){
    

    system("pause");
    return 0;
}