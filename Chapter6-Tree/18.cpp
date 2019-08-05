#include <iostream>
#include "tree.h"
using namespace std;


bool showLca(Node *root, int x){
    if(!root)return false;
    if(root->w==x)return 1;
    if(showLca(root->left, x) || showLca(root->right, x)){
        printf("%d ", root->w);
        return 1;
    }
    return 0;
}


int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    bfs(root);
    showLca(root, 9);
    destroy(root);
    return 0;
}
