#include <iostream>
#include "tree.h"
#include <queue>
#include <algorithm>
using namespace std;


int getWidth(Node* root){
    if(!root)return 0;
    queue<Node*> q;
    q.push(root);
    int width = 1;//初始状态，队列中只有一个节点，此时树的宽度为1
    while(!q.empty()){
        int n = q.size();//当前队列中的元素个数，当当前所有元素都出队列时间，队列此时的大小就是下一层元素的个数
        while(n --){
            Node* top = q.front();q.pop();
            if(top->left)q.push(top->left);
            if(top->right)q.push(top->right);
        }

        //此时队列中元素的个数就是下一层节点的个数
        width = max((int)q.size(), width);
    }
    return width;
}


int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
    int n = sizeof a/sizeof(int);
    Node* root = createCBT(a, 1, n-1);
    cout << getWidth(root) << endl;
    return 0;
}
