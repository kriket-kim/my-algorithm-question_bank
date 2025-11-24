#include <iostream>

int n, k;
std::pair<int,int> item[101];
int dp[101][100001];


int main() {
    std::cin >> n >> k;

    for(int i = 1; i <= n; i++){
        int w, v;
        std::cin >> w >> v;
        item[i] = {w,v};
    }

    for(int i = 1; i <= n; i++){
        int cweight = item[i].first;
        int cvalue = item[i].second;
        for(int j = 1; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            
            if(cweight <= j && dp[i][j] < dp[i-1][j-cweight] + cvalue)
                dp[i][j] = dp[i-1][j - cweight] + cvalue;
        }
    } 
    std::cout << dp[n][k];
}