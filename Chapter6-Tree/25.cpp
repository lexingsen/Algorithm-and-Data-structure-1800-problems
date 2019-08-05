#include <iostream>
#include "tree.h"
#include <queue>
using namespace std;


//统计二叉树中非叶子节点个树的层序遍历算法 
int countNonLeaf(Node* root){
    if(!root)return 0;
    queue<Node*> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        Node* f = q.front();q.pop();
        if(f->left || f->right)cnt ++;
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
    }
    return cnt;
}


int main(){
    return 0;
}
