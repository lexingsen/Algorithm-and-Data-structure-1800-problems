#include <iostream>
#include "tree.h"
using namespace std;


void countLeaf(Node* root, int& cnt){
    if(!root)return ;
    if(!root->left && !root->right)
        cnt ++;
    else{
        countLeaf(root->left, cnt);
        countLeaf(root->right, cnt);
    }
}


int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    int cnt = 0;
    countLeaf(root, cnt);
    cout << "leaf num: " << cnt << endl;
    return 0;
}