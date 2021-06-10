#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

const int maxn = 1000001;
int prime[maxn],pNum=0;
bool p[maxn] = {0};
void Find_Prime(int n){
    for(int i=2;i < maxn;i++){
        if(p[i] == false){
            prime[pNum++] =i;
            if(pNum >= n) break;
            for(int j = i+i;j<maxn;j+=i){
                p[j] = true;
            }
        }
    }
}

int main(){
    int M,N,count = 0;
    scanf("%d%d",&M,&N);
    Find_Prime(N);
    for(int i=M;i<=N;i++){
        printf("%d",prime[i-1]);
        count++;
        if(count % 10 != 0 && i < N) printf(" ");
        else printf("\n");
    }
    system("pause");
}