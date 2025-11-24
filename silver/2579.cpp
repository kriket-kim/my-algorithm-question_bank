#include <iostream>

int stair[301];
int score[301];

int main() {
    int n;
    std::cin >> n;
    
    for(int i = 1; i <= n; i++){
        std::cin >> stair[i];
    }
    score[1] = stair[1];
    score[2] = stair[2] + score[1];


    for(int i = 3; i <= n; i++){
        score[i] = stair[i] + std::max(stair[i-1] + score[i-3], score[i-2]);
    }

    for(int i = 0; i <= n; i++){
        std::cout << score[i] << " ";
    }
    std::cout << "\n";
    std::cout << score[n] << "\n";
}