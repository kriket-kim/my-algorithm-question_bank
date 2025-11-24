#include <iostream>

int apt[15][15];

int main() {
    for(int i = 0; i < 15; i++) apt[0][i] = i;

    for(int i = 1; i < 15; i++){
        for(int j = 1; j < 15; j++){
            apt[i][j] += apt[i][j-1] + apt[i-1][j];
        }
    }

    // for(int i = 0; i < 15; i++){
    //     for(int j = 0; j < 15; j++){
    //         std::cout << apt[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    int t;
    int k, n;
    std::cin >> t;
    for(int dt =0 ; dt < t; dt++){
        std::cin >> k >> n;
        std::cout << apt[k][n] << "\n";
    }
}