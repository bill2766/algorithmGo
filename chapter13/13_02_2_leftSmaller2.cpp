#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
#define lowbit(i) ((i)&(-i)) //lowbit写成宏定义的形式，注意括号
struct Node{
    int val; //序列元素的值
    int pos; //原始序号
}temp[maxn]; //temp数组临时存放输入数据
int A[maxn]; //离散化后的原始数组
int c[maxn]; //树状数组

//update函数将第x个整数加上v
void update(int x, int v){
    for(int i=x; i<maxn; i+=lowbit(i)){ //i<max或者i<=n都可以
        c[i] += v; //让c[i]加上v，然后让c[i+lowbit(i)]加上v
    }
}

//getSum函数返回前x个整数之和
int getSum(int x){
    int sum = 0;
    for(int i=x; i>0; i-=lowbit(i)){ //注意是i>0而不是i>=0
        sum += c[i]; //累计c[i]，然后把问题缩小为SUM(1,i-lowbit(i))
    }
    return sum; //返回和
}

bool cmp(Node a, Node b){
    return a.val < b.val;
}

int main(){
    int n;
    scanf("%d",&n);
    memset(c,0,sizeof(c)); //树状数组初值为0
    for(int i=0; i<n; i++){
        scanf("%d",&temp[i].val); //输入序列元素
        temp[i].pos = i; //原始序号
    }
    //离散化
    sort(temp,temp+n,cmp); //按val从小到大排序
    for(int i=0; i<n; i++){
        //与上一个元素值不同时，赋值为元素个数
        if(i==0 || temp[i].val != temp[i-1].val){
            A[temp[i].pos] = i+1;
        }else{ //与上一个元素值相同时，直接继承
            A[temp[i].pos] = A[temp[i-1].pos];
        }
    }
    //正式进入更新和求和操作
    //这里update的是个数
    for(int i=0; i<n; i++){
        update(A[i],1);
        printf("%d\n",getSum(A[i]-1));
    }

    return 0;
}