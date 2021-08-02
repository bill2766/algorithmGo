#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010; //总人数
const int INF = 1000000000; //无穷大

map<int,string> intToString; //编号-》姓名
map<string,int> stringToInt; //姓名-》编号
map<string,int> Gang; //head-》人数
int G[maxn][maxn] = {0}, weight[maxn] = {0}; //邻接矩阵G、点权weight
int n, k, numPerson = 0; //边数n、下限k、总人数numPerson
bool vis[maxn] = {false}; //标记是否被访问

void DFS(int nowVisit, int& head,int& numMember, int& totalValue){
    numMember++;
    vis[nowVisit] = true;
    if(weight[nowVisit] > weight[head]){
        head = nowVisit;
    }

    for(int i=0;i<numPerson;i++){
        if(G[nowVisit][i] > 0){
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if(vis[i] == false){
                DFS(i,head,numMember,totalValue);
            }
        }
    }
}

void DFSTrave(){
    for(int i=0;i<numPerson;i++){
        if(vis[i] == false){
            int head=i,numMember=0,totalValue = 0;
            DFS(i,head,numMember,totalValue);
            if(numMember > 2 && totalValue > k){
                Gang[intToString[head]] = numMember;
            }
        }
    }
}

int change(string str){
    if(stringToInt.find(str) != stringToInt.end()){ //str已经出现过
        return stringToInt[str];
    }else{ //否则新建
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}

int main(){
    int w;
    string str1,str2;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>str1>>str2>>w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1]+=w;
        weight[id2]+=w;
        G[id1][id2] += w;
        G[id1][id2] += w;
    }
    DFSTrave();

    cout<<Gang.size()<<endl;
    map<string,int>::iterator it;
    for(it=Gang.begin();it!=Gang.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}
