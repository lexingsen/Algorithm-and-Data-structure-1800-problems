#include <iostream>
#include "tree.h"
using namespace std;


//求树的高度
//递归

int getHeight(Node* root){
    if(!root)return 0;
    if(!root->left && !root->right)return 1;
    else return max(getHeight(root->left), getHeight(root->right)) + 1; 
}


int main(){
    // int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    // int n = sizeof a/sizeof(int);
    // Node* root = createCBT(a, 1, n-1);
    // // bfs(root);cout << endl;
    // Node* root = new Node;
    // root->left = root->right = NULL;
    // root->w = 10;
    cout << getHeight(root) << endl;

    destroy(root);
    return 0;
}