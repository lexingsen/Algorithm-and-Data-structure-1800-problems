#include <iostream>
#include "tree.h"
using namespace std;


Node *head;
Node *pre;
void doubleLinkedLeaf(Node *root){
    if(!root)return;
    doubleLinkedLeaf(root->left);
    if(!root->left && !root->right){
        if(!head){
            head = (Node*)malloc(sizeof(Node));
            head->left = NULL;
            head->right  = root;
            root->left = head;
            pre = root;
        }else{
            pre->right = root;
            root->left = pre;
            pre = root;
        }
    }
    doubleLinkedLeaf(root->right);
    pre->right = NULL;
}

void showList(){
    cout << head << endl;
    Node* cur = head->right;
    while(cur){
        cout << cur->w << " ";
        cur = cur->right;
    }
    cout << endl;
}


int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    bfs(root);cout << endl;
    doubleLinkedLeaf(root);
    showList();
    return 0;
}
