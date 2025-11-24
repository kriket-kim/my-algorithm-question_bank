#include <iostream>
#include <unordered_set>
#include <set>
#include <string>

std::unordered_set<std::string> set;
std::set<std::string> res;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::string name;
    for(int i = 0; i < n; i++){
        std::cin >> name;
        set.insert(name);
    }

    for(int i = 0; i < m; i++){
        std::cin >> name;
        if(set.count(name)) res.insert(name);
    }

    std::cout << res.size() << "\n";
    for(auto i : res) std::cout << i << "\n";
}