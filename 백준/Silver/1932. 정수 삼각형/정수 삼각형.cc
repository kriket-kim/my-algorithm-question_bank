#include <iostream>
#include <algorithm>
#include <cstring>

int arr[501][501];
int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    memset(arr, 0, sizeof(arr));
    int n;
    std::cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int t;
            std::cin >> t;
            arr[i][j] = std::max(arr[i-1][j], arr[i-1][j-1]) + t;
        }
    }

    int max = 0;
    for(auto i: arr[n]){
        max = std::max(max, i);
    }
    std::cout << max;
}