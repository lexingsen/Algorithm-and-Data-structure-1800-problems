#include <iostream>
#include <stack>
using namespace std;

const int M = 100;

struct node{
    int data;
    int son[12];
}tnode[M];


void preOrder(int root){
    if(root==-1)return;
    stack<node> st;
    st.push(tnode[root]);
    while(!st.empty()){
        node p = st.top();st.pop();
        printf("%d ", p.data);
        for(int i=11; i>=0; --i){
            if(p.son[i]!=-1)
                st.push(tnode[p.son[i]]);
        }
    }
    printf("\n");
}

int main(){
    return 0;
}
