// void preorder(node* root){
//     if(root == NULL){
//         return;
//     }
//     printf("%d\n",root->data);
//     preorder(root->lchild);
//     preorder(root->rchild);
// }

// void inorder(node* root){
//     if(root == NULL){
//         return;
//     }
//     inorder(root->lchild);
//     printf("%d\n",root->data);
//     inorder(root->rchild);
// }

// void postorder(node* root){
//     if(root == NULL){
//         return;
//     }
//     postorder(root->lchild);
//     postorder(root->rchild);
//     printf("%d\n",root->data);
// }

// struct node{
//     int data;
//     int layer;
//     node* lchild;
//     node* rchild;
// }

// void LayerOrder(node* root){
//     queue<node*> q;
//     root->layer = 1;
//     q.push(root);
//     while(!q.empty()){
//         node* now = q.front();
//         q.pop();
//         printf("%d\n",now->data);
//         if(now->lchild != NULL){
//             now->lchild->layer = now->layer + 1;
//             q.push(now->lchild);
//         }
//         if(now->rchild != NULL){
//             now->rchild->layer = now->layer + 1;
//             q.push(now->rchild);
//         }
//     }
// }

// node* create(int preL,int preR,int inL,int inR){
//     if(preL > preR){
//         return NULL;
//     }

//     node* root = new node;
//     root->data = pre[preL];
    
//     int k;
//     //找到k
//     for(int k=inL;k<=inR;k++){
//         if(in[k] == pre[preL]){
//             break;
//         }
//     }

//     //左子树的结点个数
//     int numLeft = k - inL;

//     root->lchild = create(preL+1,preL+numLeft,inL,k-1);

//     root->rchild = create(preL+numLeft+1,preR,k+1,inR);

//     return root;
// }