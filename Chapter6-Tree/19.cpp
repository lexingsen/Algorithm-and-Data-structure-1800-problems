#include <iostream>
#include <stack>
#include "tree.h"
using namespace std;


//非递归的算法实现：根节点到任意给定p节点上的路径
//算法思想：采用后序非递归的思想
stack<Node*> Path(Node* root, int x){
    stack<Node*> st;
    Node *p = root, *tag = NULL;
    while(p || !st.empty()){
        while(p){
            st.push(p);
            if(p->w==x)return st;
            p = p->left;

        }
        p = st.top();st.pop();
        if(!p->right || p->right==tag){
            tag = p;
            p = NULL;
        }else{
            st.push(p);
            p = p->right;
        }
    }
}


int main(){
    int a[] = {45, 33, 31, 40, 36, 41, 42, 43, 79, 74, 76, 90, 80};
    int n = sizeof a/sizeof(int);
    Node* root = NULL;
    for(int i=0; i<n; ++i)
        root = createBST(root, a[i]);
    stack<Node*> ans = Path(root, 42);

    while(!ans.empty()){
        cout << ans.top()->w << " ";
        ans.pop();
    }
    cout << endl;
    destroy(root);
    return 0;
}
