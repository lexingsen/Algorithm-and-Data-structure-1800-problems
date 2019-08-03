#include <iostream>
#include <queue>
#include <vector>
#include "tree.h"
using namespace std;


//二叉树的复制

Node* duplication(Node* root){
    if(!root)
        return NULL;
    else{
        Node* node = (Node*)malloc(sizeof(Node));
        node->w = root->w;
        node->left  = duplication(root->left);
        node->right = duplication(root->right);
        return node;
    }
}

int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    bfs(root);cout << endl;

    Node* root1 = duplication(root);
    bfs(root1);cout << endl;
    return 0; 
}