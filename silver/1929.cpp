#include <iostream>

int arr[1000001];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int m, n;
    std::cin >> m >> n;

    arr[1] = 1;
    for(int i = 2; i <= 1000000; i++){
        for(int j = 2; i*j <= 1000000; j++){
            arr[i*j] = 1;
        }
    }
    for(int i = m; i<=n; i++){
       if(!arr[i]) std::cout << i << "\n";
    }
}