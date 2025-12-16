//Union-Find, Disjoint set
//why is this gold3????
#include <iostream>
#include <cstring>

int n, m;
int parent[500001];

int find(int node) {
    if(parent[node] == -1) return node;

    return parent[node] =  find(parent[node]);
}

void setUnion(int a, int b){
    int p1 = find(a);
    int p2 = find(b);

    if(p1 == p2) return;

    if(p1 < p2){
        parent[p2] = p1;
    }
    else {
        parent[p1] = p2;
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    memset(parent, -1, sizeof(parent));
    std::cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int a, b;
        std::cin >> a >> b;
        if(find(a) == find(b) && find(a) != -1) {
            std::cout << i;
            return 0;
        }
        setUnion(a, b);
    }

    std::cout << "0";
}