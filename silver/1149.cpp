#include <iostream>
#include <algorithm>

int arr[1001][3];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int n;
    std::cin >> n ;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> arr[i][j];
        }
    }

    for(int i = 1; i < n; i++){
        arr[i][0] = arr[i][0] + std::min(arr[i-1][1], arr[i-1][2]);
        arr[i][1] = arr[i][1] + std::min(arr[i-1][0], arr[i-1][2]);
        arr[i][2] = arr[i][2] + std::min(arr[i-1][0], arr[i-1][1]);
    }
    std::cout << std::min({arr[n-1][0], arr[n-1][1], arr[n-1][2]});
}