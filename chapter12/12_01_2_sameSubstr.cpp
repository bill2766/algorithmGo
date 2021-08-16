#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007; //MOD为计算hash值时的模数
const LL P = 10000019; //P为计算hash值时的进制数
const LL MAXN = 1010; //MAXN为字符串最长长度

//powP[i]存放P^i%MOD，H1和H2分别存放str1和str2的hash值
LL powP[MAXN];
LL H1[MAXN] = {0}, H2[MAXN] = {0};

//pr1存放str1的所有<子串hash值，子串长度>，pr2同理
vector<pair<int,int> > pr1, pr2;

//init函数初始化powP函数
void init(int len){
    powP[0] = 1;
    for(int i=1; i<=len; i++){
        powP[i] = (powP[i-1] * P) % MOD;
    }
}

//calH函数计算字符串str的hash值
void calH(LL H[], string &str){
    //这里不限大小写字母，并且已经计算出来str在每一位时的值
    H[0] = str[0]; //H[0]单独处理
    for(int i=1; i<str.length(); i++){
        H[i] = (H[i-1] * P + str[i]) % MOD;
    }
}

//calSingleSubH计算H[i...j]
int calSingleSubH(LL H[], int i, int j){
    if(i == 0) return H[j]; //H[0...j]单独处理
    return ((H[j] - H[i-1] * powP[j-i+1]) % MOD + MOD) % MOD;
}

//calSubH计算所有子串的hash值，并将<子串hash值，子串长度>存入pr
void calSubH(LL H[], int len, vector<pair<int,int> >&pr){
    for(int i=0; i<len; i++){
        for(int j=i; j<len; j++){
            int hashValue = calSingleSubH(H,i,j);
            pr.push_back(make_pair(hashValue, j-i+1));
        }
    }
}

//计算pr1和pr2中相同的hash值，维护最大长度
int getMax(){
    int ans = 0;
    for(int i=0; i<pr1.size(); i++){
        for(int j=0; j<pr2.size(); j++){
            if(pr1[i].first == pr2[j].first){
                ans = max(ans, pr1[1].second);
            }
        }
    }
}

int main(){
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    init(max(str1.length(),str2.length())); //初始化powP数组

    calH(H1,str1);
    calH(H2,str2);

    calSubH(H1,str1.length(), pr1);
    calSubH(H2,str2.length(), pr2);

    printf("ans = %d\n",getMax());
    return 0;
}