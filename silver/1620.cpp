#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> s2i;
std::string i2s[100001];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::string name;
    for(int i = 1; i <= n; i++){
        std::cin >> name;
        s2i[name] = i;
        i2s[i] = name;
    }
    std::string q;
    for(int i = 0; i < m; i++){
        std::cin >> q;
        if(q[0] >= '0' && q[0] <= '9' ){
            std::cout << i2s[std::stoi(q)] << "\n";
        }
        else {
            std::cout << s2i[q] << "\n";
        }
    }
}