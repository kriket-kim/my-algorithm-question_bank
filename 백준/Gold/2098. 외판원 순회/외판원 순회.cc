#include <iostream>
#include <cstring>
#define INF 10'000'000

int n;
int edges[16][16];
int dp[16][1<<16];

int dfs(int idx, int visited){
    //have visited all - base case
    if (visited == (1 << n) - 1) {
        //there is a path to return to city 0
        if(edges[idx][0] != 0) {
            return edges[idx][0];
        }
        //cannot go from last city to city 0
        return INF;
    }
    
    //using dp
    int& ret = dp[idx][visited];
    if(ret != -1) return ret;

    //assume no path on initial
    ret = INF;
    //starting from idx 0, as 0 is visited at start
    for(int i = 1; i < n; i++) {
        //visited ith city
        if (visited & (1<<i)) continue;
        //there is no path
        if(edges[idx][i] == 0) continue;

        //assuming current city as visited, try TSP on remaining.
        int nCost = dfs(i, visited + (1 << i));
        //if there was path, record it
        if(nCost != INF) {
            ret = std::min(ret, edges[idx][i] + nCost);
        }
    }
    return ret;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    memset(dp, -1, sizeof(dp));

    std::cin >> n;
    
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> edges[i][j];
        }
    }
    //starting from 0, as it does not matter which we start
    //start with marking city 0 visited
    std::cout << dfs(0,1) << "\n";
}