#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct Interval{
    int x,y;
}I[maxn];

bool cmp(Interval a,Interval b){
    if(a.x!=b.x) return a.x>b.x; //保证情况2，总是选择左端点最大的区间
    else return a.y<b.y; //保证情况1，总是选择被包含的
}

int main(){
    int n;
    while(scanf("%d",&n) , n!=0){
        for(int i=0;i<n;i++){
            scanf("%d%d",&I[i].x,&I[i].y);
        }
        sort(I,I+n,cmp);

        int ans=1,lastX = I[0].x;
        for(int i=1;i<n;i++){
            if(I[i].y <= lastX){
                lastX = I[i].x;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}