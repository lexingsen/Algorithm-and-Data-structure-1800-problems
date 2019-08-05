#include <iostream>
#include "tree.h"
using namespace std;

const int N=100;
int bt[N];
int lca(int x, int y){
    //当x和y相等时就是x和y最近公共祖先的下标
    while(x!=y){
        if(x<y)y /= 2;
        else x /= 2;
    }
    return bt[x];
}

int main(){
    return 0;
}
