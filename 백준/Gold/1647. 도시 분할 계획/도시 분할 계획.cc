#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

struct Edge{
    int a;
    int b;
    int cost;

    bool operator< (const struct Edge& other) const{
        return cost > other.cost;
    }
};

int n, m;
int parent[100001];
int rank[100001];
std::priority_queue<struct Edge> pq;

int find(int node){
    if(parent[node] == -1){
        return node;
    }

    return parent[node] = find(parent[node]);
}

void setUnion(int a, int b){
    int p1 = find(a);
    int p2 = find(b);

    if(p1 == p2) return;

    if(rank[p1] < rank[p2]){
        parent[p1] = p2;
    }
    else {
        parent[p2] = p1;
    
        if(rank[p2] == rank[p1]) rank[p1]++;
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    memset(parent,-1,sizeof(parent));
    memset(rank,0,sizeof(rank));

    std::cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b, c;
        std::cin >> a >> b >> c;

        pq.push({a,b,c});
    }
    std::vector<struct Edge> mst;

    while(!pq.empty()){
        struct Edge cur_edge = pq.top();

        pq.pop();
        if(find(cur_edge.a) == find(cur_edge.b)) continue;

        setUnion(cur_edge.a, cur_edge.b);
        mst.push_back(cur_edge);

        if(mst.size() == n-1) break;
    }

    long long ans = 0;
    for(int i = 0; i < mst.size()-1; i++){
        ans += mst[i].cost;
    }
    std::cout << ans;
}