#include <iostream>
#include "tree.h"
using namespace std;


//显示 节点值为x的 所有公共祖先的值， 从根节点开始
bool lca(Node* root, int x){
    if(!root)return false;
    if(root->left && root->left->w==x || root->right && root->right->w==x){
        printf("lca: %d \n", root->w);
        return true;
    }else if(lca(root->left, x) || lca(root->right, x)){
        printf("lca: %d \n", root->w);
    }else
        return false;
}


int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    bfs(root);
    lca(root, 9);
    destroy(root);
    return 0;
}
