#include <iostream>
#include <algorithm>
#include <vector>

struct Node{
    int left;
    int right;

    int val;
};
struct Node nodePool[40000];

int nodeIdx = 0;

void insert(int toAdd, int curIdx){
    struct Node& toAddNode = nodePool[toAdd];
    struct Node& curNode = nodePool[curIdx];    

    //root case
    if(toAdd == curIdx){
        return;
    }

    if(toAddNode.val < curNode.val) {
        if(curNode.left != -1) insert(toAdd, curNode.left);
        else curNode.left = toAdd;
    }
    else {
        if(curNode.right != -1) insert(toAdd, curNode.right);
        else curNode.right = toAdd;
    }
}

void postfix(int idx){
    struct Node& cur = nodePool[idx];
 
    if(cur.left != -1) postfix(cur.left);
    if(cur.right != -1) postfix(cur.right);
    std::cout << cur.val << "\n";
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int a;
    while(std::cin >> a){
        nodePool[nodeIdx] = {-1, -1, a};
        insert(nodeIdx++, 0);
    }
    
    postfix(0);
}