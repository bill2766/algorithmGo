#include <cstdlib>
#include <stdio.h>
#include <set>
using namespace std;

int main(){
    set<int> st;
    // st.insert(3); //insert(x)��x����set��
    // st.insert(5);
    // st.insert(2);
    // st.insert(3);
    // //ע�⣬��֧��it < st.end()
    // for(set<int>::iterator it=st.begin();it!=st.end();it++){
    //     printf("%d ",*it);
    // }

    // for(int i=1;i<=3;i++){
    //     st.insert(i);
    // }
    // set<int>::iterator it = st.find(2); //��set�в���2�������������
    // printf("%d\n",*it);
    // //�ȼ���printf("%d\n",*(st.find(2)));

    // st.insert(100);
    // st.insert(200);
    // st.insert(100);
    // st.insert(300);
    // // st.erase(st.find(200)); //����find()�ҵ�100��Ȼ����eraseɾ����
    // st.erase(100); //ɾ��set��ֵΪ100��Ԫ��
    // for(set<int>::iterator it=st.begin();it != st.end();it++){
    //     printf("%d\n",*it);
    // }
    
    st.insert(20);
    st.insert(10);
    st.insert(40);
    st.insert(30);
    set<int>::iterator it = st.find(30);
    st.erase(it,st.end()); //ɾ��Ԫ��30��setĩβ֮���Ԫ��
    for(set<int>::iterator it=st.begin();it != st.end();it++){
        printf("%d\n",*it);
    }

    system("pause");
    return 0;
}