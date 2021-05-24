#include <cstdio>
#include <stdlib.h>

using namespace std;
const int maxn = 210;
int a[maxn];

int main(){
    int n, x;

    while(scanf("%d",&n) != EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        scanf("%d",&x);

        int i;
        for(i=0;i<n;i++){
            if(a[i] == x){
                printf("%d",i);
                break;
            }
        }

        if(i == n){
            printf("-1\n");
        }

    }

    system("pause");
    return 0;
}