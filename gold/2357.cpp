#include <iostream>
#include <vector>

std::vector<int> arr;
std::vector<int> minTree, maxTree;

void init(int node, int leftNode, int rightNode) {
    if(leftNode == rightNode) {
        minTree[node] = arr[leftNode];
        maxTree[node] = arr[leftNode];
        return;
    }

    int mid = (leftNode + rightNode) / 2;

    init(node *2 , leftNode, mid);
    init(node*2+1, mid+1, rightNode);

    minTree[node] = std::min(minTree[2*node], minTree[2*node+1]);
    maxTree[node] = std::max(maxTree[2*node], maxTree[2*node+1]);
}

int queryMin(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight){
    if(queryRight < nodeLeft || nodeRight < queryLeft) {
        return 21e8;
    }
    if(queryLeft <= nodeLeft && nodeRight <= queryRight) {
        return minTree[node];
    }

    int mid = (nodeLeft + nodeRight) / 2;

    int leftMin = queryMin(node*2, nodeLeft, mid, queryLeft, queryRight);
    int rightMin = queryMin(node*2 + 1, mid + 1, nodeRight, queryLeft, queryRight);

    return std::min(leftMin, rightMin);
}

int queryMax(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight){
        if(queryRight < nodeLeft || nodeRight < queryLeft) {
        return 0;
    }
    if(queryLeft <= nodeLeft && nodeRight <= queryRight) {
        return maxTree[node];
    }

    int mid = (nodeLeft + nodeRight) / 2;

    int leftMax = queryMax(node*2, nodeLeft, mid, queryLeft, queryRight);
    int rightMax = queryMax(node*2 + 1, mid + 1, nodeRight, queryLeft, queryRight);

    return std::max(leftMax, rightMax);
}


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    arr.resize(n);
    minTree.resize(4*n);
    maxTree.resize(4*n);    

    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    init(1, 0, n-1);

    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;

        std::cout << queryMin(1, 0, n-1, a-1, b-1) << " " 
                  << queryMax(1, 0, n-1, a-1, b-1) << "\n";
    }
}