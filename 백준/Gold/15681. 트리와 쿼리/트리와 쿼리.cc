//DP on Tree, DFS
//Note 1. as it is acyclic, just check for parent
    // there is not need to have visited array

#include <iostream>
#include <vector>
#include <cstring>

int n, r, q;
std::vector<int> edges[100001];
int dp[100001];

int dfs(int cur, int pat){
    int ret = 1;

    for(int i = 0; i < edges[cur].size(); i++){
        if(edges[cur][i] == pat) continue;
        ret += dfs(edges[cur][i], cur);
    }
    return dp[cur] = ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> r >> q;
    
    for(int i = 0; i < n-1 ; i++){
        int a, b;
        std::cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(r, -1);
    
    for(int i = 0; i < q; i++){
        int t;
        std::cin >> t;
        std::cout << dp[t] << "\n";
    }
}