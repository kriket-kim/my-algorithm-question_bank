#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

std::vector<int> vec;

int main() {
    int n;
    std::cin >> n;
    if(n == 0){
        std::cout << "0";
        return 0;
    }
    vec.resize(n);

    for(int i = 0; i < n; i++){
        std::cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end());

    double range = std::round(vec.size() * 0.15);
    int i_range = (int) range;

    double sum = 0.0;
    for(int i = i_range; i < vec.size() - i_range; i++){
        sum += vec[i];
    }
    sum /= vec.size() - (2*i_range);

    std::cout << (int) std::round(sum);
}