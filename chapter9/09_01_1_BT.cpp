/*
struct node{
    typename data;
    node* lchild;
    node* rchild;
};

node* root = NULL;

node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void search(node* root,int x,int newdata){
    if(root == NULL){
        return;
    }
    if(root->data == x){
        root->data = newdata;
    }
    search(root->lchild,x,newdata);
    search(root->rchild,x,newdata);
}

void insert(node* &root,int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }
    if(由二叉树的性质，x应该插在左子树){
        insert(root->lchild,x);
    }else{
        insert(root->rchild,x);
    }
}

node* Create(int data[],int n){
    node* root = NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}
*/