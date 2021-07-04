/*
//��������ڵ�
struct node{
    typename data;
    node* next;
}

//ʹ���½ڵ�ʱ��ʱ������Ӧ��С���ڴ�ռ�
//1. malloc
#include <cstdlib>
//��̬�����ڴ棬���ص��������ͬ�������͵�ָ��
typename* p = (typename*)malloc(sizeof(typename));
//����
int* p = (int*)malloc(sizeof(int));
node* p = (node*)malloc(sizeof(node));
//��д���߼��ǣ�
    //��������Ҫ������ڴ�ռ��С
    //���أ�ָ�����ռ��ָ�룬void*����-�������Ҫǿ��ת��Ϊ��Ӧ����
    //���ֵ����Ӧָ�����
//2. new
typename* p = new typename;
//����
int* p = new int;
node* p = new node;

//ʹ���ڴ�ռ�󣬱��뽫���ͷţ���������ڴ�й¶
//1. free()
#include <cstdlib>
//��Ӧmalloc()
free(p);
//ʵ��2��Ч��
    //1. �ͷ�ָ�����p��ָ����ڴ�ռ�
    //2. pָ��յ�ַNULL
//2. delete()
//��Ӧnew�����
delete(p);
//һ�㿼���п��Բ����⣻���Ǵӱ��ϰ���ϣ�Ӧ�������ͷſռ��ϰ��
*/

//����Ļ�������
//1. ��������
#include <cstdio>
#include <cstdlib>
struct node{
    int data;
    node* next;
};

node* create(int Array[]){
    node *p, *pre, *head; //pre���浱ǰ����ǰ���ڵ㣬headΪͷ���
    head = new node;
    head->next = NULL;
    pre = head;
    for(int i=0;i<5;i++){
        p = new node;
        p->data = Array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

int main(){
    int Array[5] = {5,3,6,1,2};
    node* L = create(Array);
    L = L->next;
    while(L != NULL){
        printf("%d ",L->data);
        L = L->next;
    } 
    system("pause");
    return 0;
}

//2. ����Ԫ�أ�����Ԫ�ظ���
int search(node* head,int x){
    int count = 0;
    node* p = head->next;
    while(p!=NULL){
        if(p->data == x){
            count ++;
        }
        p=p->next;
    }
    return count;
}

//3. ����Ԫ��
void insert(node* head, int pos, int x){
    node* p = head;
    for(int i=0;i<pos - 1;i++){
        p = p->next;
    }
    node* q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}

//4. ɾ��Ԫ��
void del(node* head, int x){
    node* p = head->next;
    node* pre = head;
    while(p!=NULL){
        if(p->data == x){
            pre->next = p->next;
            delete(p);
            p = pre->next;
        }else{
            pre = p;
            p = p->next;
        }
    }
}