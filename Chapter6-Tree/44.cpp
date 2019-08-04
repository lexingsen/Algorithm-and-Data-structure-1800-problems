#include <iostream>
#include <queue>
#include "tree.h"
using namespace std; 


void cntMoreThan50(Node* root, vector< pair<int, int> >& v){
    if(!root)return;
    queue<Node*> q;
    q.push(root);
    int layer = 1;//记录是在第几层
    while(!q.empty()){
        int n = q.size();//
        int cnt = 0;//统计当前层节点的个数，其中节点满足数据域的数值大于50这一条件
        while(n --){
            Node* f = q.front();q.pop();
            if(f->w > 50){
                cout << f->w << " ";
                cnt ++;
            }
            if(f->left)q.push(f->left);
            if(f->right)q.push(f->right);
        }
        v.push_back(make_pair(layer++, cnt));
    } 
    cout << endl;
}

int main(){
    int a[] = {0, 65, 37, 77, 48, 51, 52, 54, 73};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    bfs(root);
    vector< pair<int, int> > ans;
    cntMoreThan50(root, ans);   

    for(auto it:ans){
        cout << it.first << "th: " << it.second << endl;
    }
    cout << endl;
    destroy(root);
    return 0;
}
