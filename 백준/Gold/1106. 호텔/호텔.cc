//Knapsack problem
#include <iostream>
#include <cstring>
#include <algorithm>

#define INF 0x3f3f3f3f
int dp[21][1101];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::fill(&dp[0][0], &dp[0][0] + sizeof(dp)/sizeof(int), INF);
    int c, n;
    std::cin >> c >> n;

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        int cost, customer;
        std::cin >> cost >> customer;
    
        dp[i][0] = 0;
        for(int j = 1; j <= c+100; j++){
            //best value from previous
            dp[i][j] = dp[i-1][j];
            if(j >= customer && dp[i][j-customer != INF])
                //why i not i-1 as in classic 0-1 knapsack? because we need to use current city multiple times.
                dp[i][j] = std::min(dp[i][j], dp[i][j-customer] + cost);
        }
    }

    int ans = 21e8;
    for(int i = c; i<=c+100; i++){
        ans = std::min(ans, dp[n][i]);
    }
    std::cout << ans;
}