#include <iostream>
#include "tree.h"
using namespace std;


//利用叶子节点中的空的右链域right，将所有的叶节点从左想入链接成一个单链表
//使用中序的遍历的方式，在找到叶子时候，分两种情况处理
/*
1.pre=NULL  表示当前单链表还没有前驱节点 此时，令pre=head=root;
2.pre!=NULL 表示当前单链表已经有前驱节点了，只需要进行链接当前叶节点，链接
完成过后，更新pre为当前节点。pre->right=root;pre=root;
3.在将所有的叶子节点都链接到单链表中，此时需要让pre->next = NULL;标记单链表的结束
虽然不标记，此时pre指向的树中最后叶节点leaf，其leaf->right=pre->right=NULL;为了
清晰可见，还是显式的标记出来。
4.在本程序中，使用的是前序，其实后序和中序都是可以的，只需要改变一下链接逻辑的位置即可
*/
Node* head;
Node* pre;
void linkedLeaf(Node* root){
    if(!root)return;
    if(!root->left && !root->right){
        if(!pre)pre = head = root;
        else{
            pre->right = root;
            pre = root;
        }
    }

    linkedLeaf(root->left);
    linkedLeaf(root->right);

    pre->right = NULL;
}

void showList(){
    while(head){
        cout << head->w << " ";
        head = head->right;
    }
    cout << endl;
}



int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    bfs(root);cout << endl;

    linkedLeaf(root);
    showList();
    return 0;
}
