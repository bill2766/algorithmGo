#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    int sqr = (int)sqrt(1.0 * n); //一个浮点数取整
    for(int i = 2;i <= sqr; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

//--------------------------------------------------------------
const int maxn = 101;
int prime[maxn],pNum=0;
bool p[maxn] = {0};
void Find_Prime(){
    for(int i=1;i<maxn;i++){
        if(isPrime(i) == true){
            prime[pNum++] = i;
            p[i] = true;
        }
    }
}

int main(){
    Find_Prime();
    for(int i=0;i<pNum;i++){
        printf("%d ",prime[i]);
    }
    system("pause");
}

//--------------------------------------------------------------
const int maxn = 101;
int prime[maxn],pNum=0;
bool p[maxn] = {0};
void Find_Prime(){
    for(int i=2;i < maxn;i++){
        if(p[i] == false){
            prime[pNum++] =i;
            for(int j = i+i;j<maxn;j+=i){
                p[j] = true;
            }
        }
    }
}