#include <iostream>
#include <stack>
#include "tree.h"
using namespace std;

//非递归遍历二叉树的的算法


void preOrder(Node* root){
    if(!root)return;//空树  直接返回
    Node* p = root;//使用p代替root 进行遍历
    stack<Node*> st;//存放中间节点
    st.push(p);
    while(!st.empty()){
        p = st.top();st.pop();
        cout << p->w << " ";
        if(p->right)st.push(p->right);
        if(p->left)st.push(p->left);
    }
    cout << endl;
}


int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    preOrder(root);
    destroy(root);
    return 0;
}
