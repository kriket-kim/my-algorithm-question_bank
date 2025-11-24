#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

struct Edge{
    int cost;
    int a;
    int b;

    bool operator<(const struct Edge& other) const{
        return cost > other.cost;
    }
};

int v, e;
int arr[10001];
std::priority_queue<struct Edge> pq;

int find(int node){
    if(arr[node] == -1) return node;

    arr[node] = find(arr[node]);
    return arr[node];
}

void setUnion(int a, int b){
    int pat1 = find(a);
    int pat2 = find(b);

    if(pat1 == pat2) return;

    arr[pat1] = pat2;
}

int kruskal(){
    int sum = 0;
    int cnt = 0;

    while(!pq.empty()){
        struct Edge cur = pq.top();
        pq.pop();

        if(find(cur.a) == find(cur.b)) continue;

        setUnion(cur.a, cur.b);
        sum += cur.cost;
        if(cnt++ == v-1) return sum;
    }
    return sum;

}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    memset(arr, -1, sizeof(arr));

    std::cin >> v >> e;

    for(int i = 0; i < e; i++){
        int a, b ,c;
        std::cin >> a >> b >> c;
        pq.push({c,a,b});
    }

    std::cout << kruskal();
}