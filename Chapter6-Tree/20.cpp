#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

vector< vector<int> > res;
vector< vector<int> > dfs(Node* root, vector<int>& path){
    if(!root)return res;
    path.push_back(root->w);
    if(!root->left && !root->right){
        res.push_back(path);
    }else{
        dfs(root->left, path);
        dfs(root->right, path);
    }
    path.pop_back();//这一步至关重要  保证回溯时不会出现重复的节点
    return res;
}


int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    vector<int> path;
    vector< vector<int> > ans = dfs(root, path);

    for(int i=0; i<ans.size(); ++i){
        cout << "path"<< i << ":";
        for(int j=0; j<ans[i].size(); ++j){
            cout << ans[i][j];
            if(j!=ans[i].size()-1)
                cout << " ->";
        }
        cout << endl;
    }
    cout << endl;
    bfs(root);
    destroy(root);
    return 0;
}