#include <iostream>
#include "tree.h"
#include <vector>
using namespace std;

int getHeight(Node* root){
    if(!root)return 0;
    if(!root->left && !root->right)return 1;
    else return max(getHeight(root->left), getHeight(root->right)) + 1;
}

vector<int> path;
vector<int> longestPath(Node* root){
    if(!root)return path;
    if(!root->left && !root->right)
        path.push_back(root->w);    
    else{
        path.push_back(root->w);
        int leftHeight  = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if(leftHeight >= rightHeight)
            longestPath(root->left);
        else
            longestPath(root->right);
    }    
    return path;
}



int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8, 9, 10, 11, 12, 13, 14, 15, 16};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    vector<int> ans = longestPath(root);
    for(int i: ans){
        cout << i << " ";
    }
    cout << endl;
    destroy(root);
    return 0;
}