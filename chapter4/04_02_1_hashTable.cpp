#include <cstdio>
#include <stdlib.h>

// using namespace std;

// const int maxn = 100010;
// bool hashTable[maxn] = {false};

// int main(){
//     //m是否在n出现过
//     int n,m,x;
//     scanf("%d%d",&n,&m);
//     printf("n m: %d %d\n",n,m);
//     for(int i=0;i<n;i++){
//         scanf("%d",&x);
//         printf("input one value\n");
//         hashTable[x] = true;
//     }
//     for(int i=0;i<m;i++){
//         scanf("%d",&x);
//         if(hashTable[x] == true){
//             printf("YES\n");
//         }else{
//             printf("NO\n");
//         }
//     }

//     system("pause");
//     return 0;
// }

/*
5 3
n m: 5 3
8 3 7 6 2
input one value
input one value
input one value
input one value
input one value
7 4 2
YES
NO
YES
*/

const int maxn = 100010;
int hashTable[maxn] = {0};

int main(){
    //m是否在n出现过
    int n,m,x;
    scanf("%d%d",&n,&m);
    printf("n m: %d %d\n",n,m);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        printf("input one value\n");
        hashTable[x]++;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        printf("%d\n",hashTable[x]);
    }

    system("pause");
    return 0;
}