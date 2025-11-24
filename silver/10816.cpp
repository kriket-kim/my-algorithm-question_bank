#include <iostream>
#include <map>

std::map<int,int> map;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int tmp; std::cin >> tmp;

        map[tmp]++;
    }

    int m;
    std::cin >> m;
    for(int i = 0; i < m; i++){
        int q;
        std::cin >> q;
        std::cout << map[q] << " ";
    }
}