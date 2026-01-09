#include <iostream>
#include <queue>
#include <vector>

std::vector<std::pair<int,int>> edges[20001];
std::priority_queue<std::pair<int,int>> pq;
int dist[20001];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::fill(dist, dist+20001, 10e8);
    int v, e;
    std::cin >> v >> e;
    
    int start;
    std::cin >> start;

    int st, ed, c;
    for(int i = 0; i < e; i++){
        std::cin >> st >> ed >> c;
        edges[st].push_back({c, ed});
    }

    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()){
        int cur_node = pq.top().second;
        int cur_cost = -pq.top().first;
        //std::cout << "DEBUG: " <<cur_cost << "\n";
        pq.pop();

        if(cur_cost > dist[cur_node]) continue;
        for(int i = 0; i < edges[cur_node].size(); i++){
            int next = edges[cur_node][i].second;
            int nweight = cur_cost + edges[cur_node][i].first;

            if(nweight > dist[next]) continue;

            dist[next] = nweight;
            pq.push({-nweight, next});
        }
    }

    for(int i = 1; i <= v; i++){
        if(dist[i] == 10e8) std::cout << "INF\n";
        else std::cout << dist[i] << "\n";
    }
}