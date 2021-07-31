/*
#include <stdlib.h>
#include <cstdio>
#include <set>

using namespace std;

const int maxn = 210;
int father[maxn];

int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

//合并
void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

void printCur(int n){
    printf("\n");
    for(int i=1;i<n+1;i++){
        printf("%d:%d\n",i,father[i]);
    }
}


int main(){
    //初始化
    for(int i =1;i <= maxn;i++){
        father[i] = i;
    }

    int n, m;
    scanf("%d%d",&n,&m);
    
    //交朋友
    int b1,b2;
    for(int i=0;i<m;i++){
        scanf("%d%d",&b1,&b2);
        father[b1] = b2;
    }

    
    set<int> fathers;
    for(int i=1;i<n+1;i++){
        fathers.insert(findFather(i));
    }
    int num = fathers.size();

    printf("num:%d",num);
    printCur(n);

    return 0;
}
*/

#include <cstdio>
const int N = 110;
int father[N];
bool isRoot[N];

int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }

    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

void init(int n){
    for(int i=1;i<=n;i++){
        father[i] = i;
        isRoot[i] = false;
    }
}

int main(){
    int n,m;
    int a,b;
    init(n);
    for(int i =0;i<m;i++){
        scanf("%d%d",&a,&b);
        Union(a,b);
    }
    for(int i=1;i<=n;i++){
        isRoot[findFather(i)] = true;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans += isRoot[i];
    }
    printf("%d\n",ans);
    return 0;

}