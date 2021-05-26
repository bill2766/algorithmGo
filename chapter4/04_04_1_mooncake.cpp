#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;
struct mooncake{
    double store;
    double price;
    double sell;
}cake[1010];

bool cmp(mooncake a,mooncake b){
    return a.price > b.price;
}

int main(){
    //月饼种类数
    int N = 0;
    //市场最大需求量
    int D = 0;
    //价值
    scanf("%d %d",&N,&D);
    // cout<<N<<" "<<D<<endl;

    for (int i=0;i<N;i++){
        scanf("%lf",&cake[i].store);
    }
    for (int i=0;i<N;i++){
        scanf("%lf",&cake[i].sell);
        //计算价值
        cake[i].price = cake[i].sell/cake[i].store;
    }
    sort(cake,cake+N,cmp);
    
    double ans;
    for(int i=0;i<N;i++){
        if(D >= cake[i].store){
            D -= cake[i].store;
            ans += cake[i].sell;
        }else{
            ans+= D *cake[i].price;
            break;
        }
    }
    printf("%.2f\n",ans);

    system("pause");
    return 0;
}