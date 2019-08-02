//统计二叉树中度为1的节点的个数

#include <iostream>
#include <queue>
#include "tree.h"
using namespace std;

int countDegreeOfOne(Node* root){
    if(!root)return 0;
    queue<Node*> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        Node* f = q.front();q.pop();
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
        if((f->left && !f->right)  || (!f->left && f->right))cnt ++;
    }
    return cnt;
}


int main(){
    int a[] = {6, 3, 1, 4, 5, 10, 7, 13, 11, 10};
    int n = sizeof a/sizeof(int);
    Node* root=NULL;
    for(int& i:a)
        root = createBST(root, i);
    cout << countDegreeOfOne(root) << endl;

    destroy(root);
}
