//dijikstra
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring> 

std::vector<std::pair<int,int>> vec[1001];
std::priority_queue<std::pair<int,int>> pq;
int min_cost[1001];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;
    std::fill(min_cost, min_cost+1001, 1e9);

    for(int i = 0; i < m; i++){
        int st, ed, cost;
        std::cin >> st >> ed >> cost;
        vec[st].push_back({ed, cost});
    }
    int st, targ;
    std::cin >> st >> targ;

    min_cost[st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        int ccost = -pq.top().first;
        int ccity = pq.top().second;
        pq.pop();

        if(ccost > min_cost[ccity]) continue;

        for(int i = 0; i < vec[ccity].size(); i++){
            int ncity = vec[ccity][i].first;
            int ncost = vec[ccity][i].second + ccost;

            if(ncost >= min_cost[ncity]) continue;

            min_cost[ncity] = std::min(min_cost[ncity], ncost);
            pq.push({-ncost, ncity});
        }
    }
    std::cout << min_cost[targ];
}