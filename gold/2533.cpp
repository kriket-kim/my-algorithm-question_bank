#include <iostream>
#include <vector>
#include <cstring>

int n;
std::vector<int> edges[1000001];
int dp[1000001][2];

void dfs(int idx, int parent){
    dp[idx][0] = 0;
    dp[idx][1] = 1;

    for(int i = 0; i < edges[idx].size(); i++){
        if(edges[idx][i] == parent) continue;
        dfs(edges[idx][i], idx);

        dp[idx][1] += std::min(dp[edges[idx][i]][0], dp[edges[idx][i]][1]);
        dp[idx][0] += dp[edges[idx][i]][1];
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    memset(dp, (1<<7)-1, sizeof(dp));
    std::cin >> n;

    for(int i = 0; i < n-1; i++){
        int st, ed;
        std::cin >> st >> ed;
        edges[st].push_back(ed);
        edges[ed].push_back(st);
    }

    dfs(1, 0);

    std::cout << std::min(dp[1][0], dp[1][1]);
}