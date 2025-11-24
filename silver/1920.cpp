#include <iostream>
#include <unordered_set>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::unordered_set<int> us;

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        int t;
        std::cin >> t;
        if(!us.count(t)) us.insert(t);
    }

    int m;
    std::cin >> m;
    for(int i = 0; i < m; i++){
        int t;
        std::cin >> t;
        std::cout << us.count(t) << "\n";
    }
}