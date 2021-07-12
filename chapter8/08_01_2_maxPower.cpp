#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 30;
int n, k, x, maxSumSqu = -1, A[maxn]; //kΪҪ������
vector<int> temp,ans;
void DFS(int index, int nowK, int sum, int sumSqu){
    if(nowK == k && sum == x){
        if(sumSqu > maxSumSqu){
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    if(index == n || nowK > k || sum > x) return;
    //ѡindex����
    temp.push_back(A[index]);
    DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
    temp.pop_back();
    //��ѡindex����
    DFS(index+1,nowK,sum,sumSqu);
}