#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

void insert(node* &root, int data){
    if(root == NULL){
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
}

void preOrder(node* root,vector<int> &vi){
    if(root == NULL) return;
    vi.push_back(root->data);
    preOrder(root->left,vi);
    preOrder(root->right,vi);
}

void preOrderMirror(node* root, vector<int> &vi){
    if(root==NULL) return;
    vi.push_back(root->data);
    preOrderMirror(root->left,vi);
    preOrderMirror(root->right,vi);
}

void postOrder(node* root,vector<int> &vi){
    if(root == NULL) return;
    postOrder(root->left,vi);
    postOrder(root->right,vi);
    vi.push_back(root->data);
}

void postOrderMirror(node* root, vector<int> &vi){
    if(root == NULL) return;
    postOrderMirror(root->right,vi);
    postOrderMirror(root->left,vi);
    vi.push_back(root->data);
}

vector<int> origin,pre, preM, post, postM;
int main(){
    int n,data;
    node* root = NULL;
    
}