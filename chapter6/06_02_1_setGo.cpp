#include <cstdlib>
#include <stdio.h>
#include <set>
using namespace std;

int main(){
    set<int> st;
    // st.insert(3); //insert(x)将x插入set中
    // st.insert(5);
    // st.insert(2);
    // st.insert(3);
    // //注意，不支持it < st.end()
    // for(set<int>::iterator it=st.begin();it!=st.end();it++){
    //     printf("%d ",*it);
    // }

    // for(int i=1;i<=3;i++){
    //     st.insert(i);
    // }
    // set<int>::iterator it = st.find(2); //在set中查找2，返回其迭代器
    // printf("%d\n",*it);
    // //等价于printf("%d\n",*(st.find(2)));

    // st.insert(100);
    // st.insert(200);
    // st.insert(100);
    // st.insert(300);
    // // st.erase(st.find(200)); //利用find()找到100，然后用erase删除它
    // st.erase(100); //删除set中值为100的元素
    // for(set<int>::iterator it=st.begin();it != st.end();it++){
    //     printf("%d\n",*it);
    // }
    
    st.insert(20);
    st.insert(10);
    st.insert(40);
    st.insert(30);
    set<int>::iterator it = st.find(30);
    st.erase(it,st.end()); //删除元素30至set末尾之间的元素
    for(set<int>::iterator it=st.begin();it != st.end();it++){
        printf("%d\n",*it);
    }

    system("pause");
    return 0;
}