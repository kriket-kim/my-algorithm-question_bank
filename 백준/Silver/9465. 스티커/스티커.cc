#include <iostream>
#include <cstring>
#include <algorithm>
int dp[2][100003];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        memset(dp, -1, sizeof(dp));
        dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 0;

        int n;
        std::cin >> n;
        for(int j = 0; j < 2; j++){
            for(int k = 2; k < n+2; k++){
                std::cin >> dp[j][k];
            }
        }

        for(int j = 2; j < n+2; j++){
            dp[0][j] = dp[0][j] + std::max({dp[1][j-1], dp[0][j-2], dp[1][j-2]});
            dp[1][j] = dp[1][j] + std::max({dp[0][j-1], dp[0][j-2], dp[1][j-2]});
        }
        std::cout << std::max(dp[0][n+1], dp[1][n+1]) << "\n";
    }
}