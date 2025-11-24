#include <iostream>
#include <algorithm>

float scores[1001];

int main() {
    float max = 0;
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cin >> scores[i];
        max = std::max(max, scores[i]);
    }

    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += (scores[i] / max) * 100; 
    }
    sum /= n;

    std::cout << sum;
}