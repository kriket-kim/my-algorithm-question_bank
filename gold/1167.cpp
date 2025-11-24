#include <iostream>
#include <vector>

std::vector<std::vector<std::pair<int,int>>> edges;
std::vector<int> dist;
int n;

void dfs(int idx, int cost){
    for(int i = 0; i < edges[idx].size(); i++){
        int nxt_idx = edges[idx][i].first;
        int nxt_cost = edges[idx][i].second;

        if(dist[nxt_idx] < nxt_cost + cost) continue;
        
        dist[nxt_idx] = nxt_cost + cost;
        dfs(nxt_idx, cost + nxt_cost);
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;

    dist.resize(n, 21e8);
    edges.resize(n);

    for(int i = 0; i < n; i++){
        int idx;
        std::cin >> idx;
        while(true){
            int t;
            std::cin >> t;
            if (t == -1) break;
            
            int w;
            std::cin >> w;
            edges[idx-1].push_back({t-1,w});
            //edges[t-1].push_back({idx-1,w});
        }
    }
    dist[0] = 0;
    dfs(0, 0);
    int st = 0, w = -1;
    for(int i = 0; i < n; i++){
        if(w < dist[i]){
            st = i;
            w = dist[i];
        }
    }

    dist.clear();
    dist.resize(n, 21e8);
    dist[st] = 0;
    dfs(st, 0);

    w = -1;
    for(int i = 0; i < n; i++){
        w = std::max(w, dist[i]);
    }
    std::cout << w;
}