#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

void search(node* root,int x){
    if(root == NULL){
        printf("search failed\n");
        return;
    }
    if(root->data == x){
        printf("%d\n",root->data);
    }else if(root->data > x){
        search(root->lchild,x);
    }else{
        search(root->rchild,x);
    }
}

node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void insert(node* &root, int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }else{
        if(root->data > x){
            insert(root->lchild,x);
        }else if(root->data == x){
            return;
        }else{
            insert(root->rchild,x);
        }
    }
}

node* Create(int data[],int n){
    node* root = NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}

node* findMax(node* root){
    while(root->rchild != NULL){
        root = root->rchild;
    }
    return root;
}

node* findMin(node* root){
    while(root->lchild != NULL){
        root = root->lchild;
    }
    return root;
}

void deleteNode(node* &root,int x){
    if(root == NULL){
        return;
    }
    if(root->data == x){
        if(root->lchild == NULL && root->rchild == NULL){
            root = NULL;
        }else if(root->lchild != NULL){
            node* pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild,pre->data);
        }else{
            node* next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild,next->data);
        }
    }else if(root->data > x){
        deleteNode(root->lchild,x);
    }else{
        deleteNode(root->rchild,x);
    }
}