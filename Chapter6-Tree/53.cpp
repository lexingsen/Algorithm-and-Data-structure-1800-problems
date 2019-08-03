#include <iostream>
#include <queue>
#include "tree.h"
using namespace std;

//递归实现二叉树的复制
Node* duplication(Node* root){
    if(!root)return NULL;
    else{
        Node* node = (Node*)malloc(sizeof(Node));
        node->w = root->w;
        node->left = duplication(root->left);
        node->right = duplication(root->right);
        return node;
    }
}

//非递归实现二叉树的复制
Node* nouRecursiveDup(Node* root){
    if(!root)return NULL;
    queue< pair<Node*, Node**> > q;
    Node* ans = NULL;
    q.push(make_pair(root, &ans));

    
    while(!q.empty()){
        auto f = q.front();q.pop();
        (*f.second) = (Node*)malloc(sizeof(Node));
        (*f.second)->w = f.first->w;

        //f.second->right = f.second->left = NULL;
        if(f.first->left)
            q.push(make_pair(f.first->left, &(*f.second)->left));
        else
            (*f.second)->left = NULL;
        if(f.first->right)
            q.push(make_pair(f.first->right, &(*f.second)->right));
        else
            (*f.second)->right = NULL;
    }
    return ans;
}



int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    bfs(root);cout << endl;
    bfs(nouRecursiveDup(root));
    return 0;
}