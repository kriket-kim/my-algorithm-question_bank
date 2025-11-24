#include <iostream>
#include <vector>

std::vector<long long> segTree, arr;

void init(int node, int nodeLeft, int nodeRight){
    if(nodeLeft == nodeRight) {
        segTree[node] = arr[nodeLeft];
        return;
    }

    int mid = (nodeLeft + nodeRight) / 2;

    init(2 * node, nodeLeft, mid);
    init(2 * node + 1, mid + 1, nodeRight);

    segTree[node] = segTree[2*node] + segTree[2*node+1];
}

void update(int node, int nodeLeft, int nodeRight, int queryIndex, int value){
    if(queryIndex < nodeLeft || nodeRight < queryIndex) {
        return;
    }

    if(nodeLeft == nodeRight){
        segTree[node] = value;
        arr[nodeLeft] = value;
        return;
    }

    int mid = (nodeLeft + nodeRight) / 2;

    update(2*node, nodeLeft, mid, queryIndex, value);
    update(2*node + 1, mid + 1, nodeRight, queryIndex, value);

    segTree[node] = segTree[2*node] + segTree[2*node + 1];
}

long long query(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
    if(queryRight <nodeLeft || nodeRight < queryLeft) {
        return 0;
    }
    if(queryLeft <= nodeLeft && nodeRight <= queryRight) {
        return segTree[node];
    }

    int mid = (nodeLeft + nodeRight) / 2;

    long long left = query(2*node, nodeLeft , mid, queryLeft, queryRight);
    long long right = query(2*node +1, mid + 1, nodeRight, queryLeft, queryRight);

    return left + right;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;
    arr.resize(n);
    segTree.resize(4*n);

    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    init(1, 0, n-1);

    for(int i = 0; i < q; i++){
        int x, y, a, b;
        std::cin >> x >> y >> a >> b;

        std::cout << query(1, 0, n-1, std::min(x-1, y-1), std::max(x-1,y-1)) << "\n";
        update(1, 0, n-1, a-1, b);
    }
}