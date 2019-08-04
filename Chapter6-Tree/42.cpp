#include <iostream>
#include <stack>
#include "tree.h"
using namespace std;


void postOrder(Node* root){
    if(!root)return;
    Node *p=root, *tag=NULL;//p代替root进行遍历  tag表示已经被访问过的节点
    stack<Node*> st;
    while(p || !st.empty()){
        while(p){
            st.push(p);
            p = p->left;
        }
        p = st.top();st.pop();
        //右边子树为NULL 或者右子树已经被访问过了
        if(!p->right || p->right==tag){
            cout << p->w << " ";
            tag = p;//更新被访问过的节点
            p = NULL;
        }else{   //(p->right&&p->left!=tag)
            st.push(p);
            p = p->right;
        }
    }
    cout << endl;
}

int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    postOrder(root);
    destroy(root);
    return 0;
}
