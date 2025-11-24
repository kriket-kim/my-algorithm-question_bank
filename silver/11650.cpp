#include <iostream>
#include <set>

std::set<std::pair<int, int>> s;

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int x,  y;
        std::cin >> x >> y;
        s.insert({x,y});
    }

    for(auto i: s){
        std::cout << i.first << " " << i.second << "\n";
    }
}