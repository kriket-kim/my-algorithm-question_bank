#include <iostream>
#include <vector>
#include <algorithm>

int n, m, k;
std::vector<long long> segTree, ir;

void init(int node, int nodeLeft, int nodeRight){
    if(nodeLeft == nodeRight){
        segTree[node] = ir[nodeLeft];
        return;
    }

    int mid = (nodeLeft + nodeRight) / 2;

    init(2*node, nodeLeft, mid);
    init(2*node+1, mid+1, nodeRight);

    segTree[node] = (segTree[2*node] * segTree[2*node+1]) % 1000000007;
}

void update(int node, int nodeLeft, int nodeRight, int queryRange, int value){
    if(queryRange < nodeLeft || nodeRight < queryRange) return;

    if(nodeLeft == nodeRight) {
        segTree[node] = value;
        return;
    }

    int mid = (nodeLeft + nodeRight) / 2;

    update(2*node, nodeLeft, mid, queryRange, value);
    update(2*node+1, mid+1, nodeRight, queryRange, value);

    segTree[node] = (segTree[2*node] * segTree[2*node+1]) % 1000000007;
}

long long query(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight){
    if(queryRight < nodeLeft || nodeRight < queryLeft) {
        return 1;
    }

    if(queryLeft <= nodeLeft && nodeRight <= queryRight){
        return segTree[node];
    }

    int mid = (nodeLeft + nodeRight) / 2;

    long long left = query(2*node, nodeLeft, mid, queryLeft, queryRight);
    long long right = query(2*node+1, mid+1, nodeRight, queryLeft, queryRight);

    return (left * right ) % 1000000007;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> m >> k;

    ir.resize(n);
    segTree.resize(4*n);
    
    for(int i = 0; i < n; i++){
        std::cin >> ir[i];
    }

    init(1, 0, n-1);
    
    for(int i = 0; i < m+k; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        if(a == 1){
            update(1, 0, n-1, b-1, c);
        }
        else {
            std::cout << query(1, 0, n-1, b-1, c-1) << "\n";
        }
    }
}