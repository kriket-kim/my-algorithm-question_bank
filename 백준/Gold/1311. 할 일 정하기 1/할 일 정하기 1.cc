//dp, bitmasking
//similar to TSP, the goal is to use bitmask to mark on
//which job is finished
#include <iostream>
#include <cstring>

#define INF 100'000'000
int dp[20][(1<<20)];
int edges[20][20];
int n;

int dfs(int idx, int finished){
    if(finished == (1<<n) - 1) {
        return 0;
    }

    int& ret = dp[idx][finished];
    if(ret != -1) return ret;

    ret = INF;
    for(int i = 0; i < n; i++){
        if(finished & (1 << i)) continue;
        int nCost = dfs(idx + 1, finished | (1<<i));

        if(nCost != INF){
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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> edges[i][j];
        }
    }

    std::cout << dfs(0,0);
}