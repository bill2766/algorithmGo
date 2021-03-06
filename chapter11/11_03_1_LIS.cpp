#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100;
int A[N], dp[N];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }

    int ans = -1;
    for(int i=1; i<=n; i++){
        dp[i] = 1; //边界初始条件（即先假设每个元素自成一个子序列）
        for(int j=1; j<i; j++){
            if(A[i] >= A[j] && (dp[j] + 1) > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}

/*
8
1 2 3 -9 3 9 0 11
*/

//6