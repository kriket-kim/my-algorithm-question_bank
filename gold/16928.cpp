#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> edges;
std::vector<int> shortcut;
std::vector<int> dist;

std::queue<int> q;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    edges.resize(101);
    dist.resize(101, 21e8);
    shortcut.resize(101);

    int x, y;
    for(int i = 0; i < n; i++){
        std::cin >> x >> y;
        edges[x].push_back(y);
        shortcut[x] = 1;
    }
    for(int i = 0; i < m; i++){
        std::cin >> x >> y;
        edges[x].push_back(y);
        shortcut[x] = 1;
    }

    for(int i = 1; i <= 100;i++){
        if(edges[i].size() != 0) continue;

        for(int j = 1; j <= 6; j++){
            if(i + j <= 100) edges[i].push_back(i + j);
        }
    }
    
    q.push(1);
    dist[1] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(int i = 0; i < edges[cur].size(); i++){
            int next = edges[cur][i];
            int nc = shortcut[cur] == 1 ? dist[cur] : dist[cur] + 1; 
            if(dist[next] >= nc){
                q.push(next);
                dist[next] = nc;
            }
        }
    }
    std::cout << dist[100];
}