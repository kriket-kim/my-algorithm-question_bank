#include <iostream>
#include <vector>

int n, m, k;

long long a[1000001];

std::vector<long long> segtree;

void init(int node, int nodeLeft, int nodeRight){
    if(nodeLeft == nodeRight){
        segtree[node] = a[nodeLeft];
        return;
    }

    int mid = (nodeLeft + nodeRight) / 2;

    init(node * 2, nodeLeft, mid);

    init(node * 2 + 1, mid+1, nodeRight);

    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

void update(int node, int nodeLeft, int nodeRight, int queryIndex, long long value){
    if( queryIndex < nodeLeft || nodeRight < queryIndex){
        return;
    }

    if(nodeLeft == nodeRight) {
        segtree[node] = value;
        return;
    }

    int mid = (nodeLeft + nodeRight) / 2;

    update(node * 2, nodeLeft, mid, queryIndex, value);

    update(node * 2 + 1, mid+1, nodeRight, queryIndex, value);

    segtree[node] = segtree[2*node] + segtree[2 * node + 1];
}

long long query(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight){
    if (queryRight < nodeLeft || nodeRight < queryLeft){
        return 0;
    }

    if(queryLeft <= nodeLeft && nodeRight <= queryRight) {
        return segtree[node];
    }

    int mid = (nodeLeft + nodeRight) / 2;

    long long leftSum = query(node * 2, nodeLeft, mid, queryLeft, queryRight);

    long long rightSum = query(node * 2 + 1, mid + 1, nodeRight, queryLeft, queryRight);

    return leftSum + rightSum;
}

int main () {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m >> k;
    
    segtree.resize(4*n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    init(1, 0, n-1);

    for(int i = 0; i < m + k; i++){
        long long  a, b, c;
        std::cin >> a >> b >> c;
        if(a == 1){
            update(1, 0, n-1, b-1, c);
        }
        else {
            std::cout << query(1, 0, n-1, b-1, c-1) << "\n";
        }
    }
}