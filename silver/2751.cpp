#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec;

int main () {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    vec.resize(n);

    for(int i = 0; i < n; i++){
        std::cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end());
    for(auto i: vec) std::cout << i << "\n";

}