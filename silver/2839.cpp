#include <iostream>
#include <cstring>
#include <algorithm>

int map[5006];

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i <= n; i++){
        map[i] = 21e8;
    }
    map[0] = 0;

    for(int i = 0; i < n; i++){
        map[i+3] = std::min(map[i]+1, map[i+3]);
        map[i+5] = std::min(map[i]+1, map[i+5]);
    }
    if(map[n] == 21e8) std::cout << -1;
    else std::cout << map[n];
}