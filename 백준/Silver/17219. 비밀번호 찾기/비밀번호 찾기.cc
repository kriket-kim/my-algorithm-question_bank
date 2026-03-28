#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> site2pw;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    for(int i = 0; i < n; i++){
        std::string a, b;
        std::cin >> a >> b;

        site2pw.insert({a,b});
    }

    for(int i = 0; i < m; i++){
        std::string tmp;
        std::cin >> tmp;
        std::cout << site2pw[tmp] << "\n";
    }
}