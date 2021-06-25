#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    vector<int> vi;
    for(int i=5;i<=9;i++){
        vi.push_back(i);
    }
    // vi.pop_back();
    
    // vi.clear();
    // printf("%d\n",vi.size());
    // vi.insert(vi.begin()+2,-1); //将-1插入vi[2]的位置
    // vi.erase(vi.begin()+3);
    vi.erase(vi.begin()+1,vi.begin()+4); //删除vi[1]、vi[2]、vi[3]
    for(int i=0;i<vi.size();i++){
        printf("%d ",vi[i]);
    }
    system("pause");
    return 0;
}