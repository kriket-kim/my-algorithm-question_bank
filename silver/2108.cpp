#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

std::vector<int> vec;
std::map<int,int> map;

int main() {
    int n;
    std::cin >> n;

    double mean = 0;
    int min = 21e8, max = -21e8;

    for(int i = 0; i < n; i++){
        int tmp;
        std::cin >> tmp;
        vec.push_back(tmp);
        
        map[tmp] ++;

        mean += tmp;
        min = std::min(min, tmp);
        max = std::max(max, tmp);
    }

    std::cout << (long long) std::round(mean / n) << "\n";
    std::sort(vec.begin(), vec.end());
    std::cout << vec[n/2] << "\n";
    
    std::vector<std::pair<int,int>> freq;
    for(auto i: map) freq.push_back({-i.second, i.first});
    std::sort(freq.begin(), freq.end());

    if(freq[0].first == freq[1].first){
        std::cout << freq[1].second << "\n";    
    }
    else std::cout << freq[0].second << "\n";

    std::cout << max - min << "\n";
}