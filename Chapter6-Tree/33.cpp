#include <iostream>
#include "tree.h"
#include <queue>
using namespace std;

//自上而下，自右而左的层序遍历
void rbfs(Node* root){
    if(!root)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* f = q.front();q.pop();
        cout << f->w << " ";
        if(f->right)q.push(f->right);
        if(f->left)q.push(f->left);
    }
    cout << endl;
}


int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    rbfs(root);

    destroy(root);
    return 0;
}