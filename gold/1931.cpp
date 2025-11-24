#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int,int>> vec;

int main() {
    int n;
    std::cin >> n;    
    for(int i = 0; i < n; i++){
        int st, ed;
        std::cin >> st >> ed;
        vec.push_back({ed, st});
    }

    std::sort(vec.begin(), vec.end());
    int cnt = 0;
    int st = 0;
    for(auto i: vec){
        if(i.second < st) continue;

        cnt++;
        st = i.first;
    } 

    std::cout << cnt;
}