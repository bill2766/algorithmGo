/*
//定义链表节点
struct node{
    typename data;
    node* next;
}

//使用新节点时临时分配相应大小的内存空间
//1. malloc
#include <cstdlib>
//动态申请内存，返回的是申请的同变量类型的指针
typename* p = (typename*)malloc(sizeof(typename));
//例子
int* p = (int*)malloc(sizeof(int));
node* p = (node*)malloc(sizeof(node));
//其写法逻辑是：
    //参数：需要申请的内存空间大小
    //返回：指向这块空间的指针，void*类型-》因此需要强制转换为对应类型
    //最后赋值给对应指针变量
//2. new
typename* p = new typename;
//例子
int* p = new int;
node* p = new node;

//使用内存空间后，必须将其释放，以免造成内存泄露
//1. free()
#include <cstdlib>
//对应malloc()
free(p);
//实现2个效果
    //1. 释放指针变量p所指向的内存空间
    //2. p指向空地址NULL
//2. delete()
//对应new运算符
delete(p);
//一般考试中可以不在意；但是从编程习惯上，应该养成释放空间的习惯
*/

//链表的基本操作
//1. 创建链表
#include <cstdio>
#include <cstdlib>
struct node{
    int data;
    node* next;
};

node* create(int Array[]){
    node *p, *pre, *head; //pre保存当前结点的前驱节点，head为头结点
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

//2. 查找元素，返回元素个数
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

//3. 插入元素
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

//4. 删除元素
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