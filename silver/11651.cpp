#include <iostream>
#include <set>

std::set<std::pair<int,int>> set;

int main() {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        std::cin >> x >> y;
        set.insert({y,x});
    }

    for(auto i: set){
        std::cout << i.second << " " <<i.first << "\n";
    }
}