#include <iostream>
#include "tree.h"
using namespace std;


//判断是否是正则二叉树
//正则二叉树定义：所有分支节点的度为2的二叉树称为正则二叉树
//分支节点：度不为0的节点称为分支节点
bool ishashTwoSon(Node* root){
    if(root->left && root->right)
        return true;
    else
        return false;
}

bool isBranchNode(Node* root){
    if(!root)return false;
    if((root->left) || (root->right) || (root->left && root->right))
        return true;
    return false;
}

bool isRegBT(Node* root){
    if(!root)return false;
    if(isBranchNode(root) && ishashTwoSon(root))
        return true;
    return isRegBT(root->left) && isRegBT(root->right);
}

int main(){
    int a[] = {0, 65, 37, 77, 48, 51, 52, 54, 73, 94};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    bfs(root);

    cout << isRegBT(root) << endl;
    return 0;
}
