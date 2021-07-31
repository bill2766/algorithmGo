
/*
//并查集用数组实现
int N;
int father[N];

//例子
//father[1]=2 表示元素1的父亲结点是元素2
father[1] = 1;
father[2] = 1;

//初始化
for(int i =1;i <= N;i++){
    father[i] = i;
}

//查找
//查找根结点，因为根结点 x = father[x]
int findFather(int x){
    while(x != father[x]){
        x = father[x];
    }
    return x;
}
//递归的写法
int findfather(int x){
    if(x == father[x]){
        return x;
    }else{
        return findfather(father[x]);
    }
}

//合并
void Union(int a, int b){
    int faA = findfather(a);
    int faB = findfather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

//查找根结点的同时，将路径上的结点都指向根结点
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
//递归写法
int findFather(int x){
    if(x == father[x]){
        return x;
    }else{
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}
*/