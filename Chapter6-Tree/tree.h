#ifndef __TREE_H__
#define __TREE_H__ 
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
using namespace std;


typedef struct node{
    int w;
    struct node *left ,*right;
}Node;


Node* createBST(Node* root, int x){
    if(!root){
        root = (Node*)malloc(sizeof(Node));
        root->w = x;
        root->left = root->right = NULL;
        return root;
    }
    if(root->w == x)
        root->w = x;
    else if(x < root->w)
        root->left = createBST(root->left, x);
    else 
        root->right = createBST(root->right, x);
    return root;
}


void inorder(Node* root){
    if(root){
        inorder(root->left);
        printf("%d ", root->w);
        inorder(root->right);
    }
}

void destroy(Node* root){
    if(root){
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}

void bfs(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* top = q.front();q.pop();
        cout << top->w << " ";
        if(top->left)q.push(top->left);
        if(top->right)q.push(top->right);
    }
}


Node* createCBT(int *a, int idx, int n){
    Node* root;
    if(idx <= n){
        root = (Node*)malloc(sizeof(Node));
        root->w = a[idx];
        if(2*idx > n)
            root->left = NULL;
        else 
            root->left = createCBT(a, 2*idx, n);
        if(2*idx + 1 > n)
            root->right = NULL;
        else
            root->right = createCBT(a, 2*idx+1, n);
    }
    return root;
}

#endif