#include <iostream>
#include <vector>
#include "tree.h"
#include <queue>
using namespace std;

vector<int> ans;
vector<int> sequenceMem(Node* root){
    if(!root)return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* f = q.front();q.pop();
        ans.push_back(f->w);
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
    }
    return ans;
}


int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    bfs(root);cout << endl;

    vector<int> res = sequenceMem(root);
    for(int i:res){
        cout << i << " ";
    }
    cout << endl;
    destroy(root);
    return 0;
}