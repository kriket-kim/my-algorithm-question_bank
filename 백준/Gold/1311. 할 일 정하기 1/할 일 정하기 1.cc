//Gemini optimization version
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define INF 100'000'000

// Optimization 1: Reduce DP array to 1D (~4MB)
//no longer 2d as we only care about jobs finished
int dp[1 << 20]; 
int edges[20][20];
int n;

// Optimization 2: Remove 'idx' parameter
//why is this possible? we can integrate idx with popcount.
int dfs(int finished) {
    if (finished == (1 << n) - 1) {
        return 0;
    }

    if (dp[finished] != -1) return dp[finished];

    // Calculate idx based on how many bits are set in 'finished'
    // __builtin_popcount returns the number of 1s in the integer
    int idx = __builtin_popcount(finished); 

    int ret = INF;
    for (int i = 0; i < n; i++) {
        // If job i is not taken
        if (!(finished & (1 << i))) {
            int nCost = dfs(finished | (1 << i));
            // Direct comparison without separate check is safe if nCost is standard INF
            ret = std::min(ret, edges[idx][i] + nCost);
        }
    }

    return dp[finished] = ret;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    // Initialize only the 1D array
    std::memset(dp, -1, sizeof(dp));

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> edges[i][j];
        }
    }

    // Call with just the initial mask
    std::cout << dfs(0);
}