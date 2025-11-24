#include <iostream>
#include <set>
#include <string>

struct comp{
    bool operator() (const std::string& a, const std::string& b) const{
        if(a.length() == b.length()) {
            return a < b;
        }
        return a.length() < b.length();
    }
};

std::set<std::string, comp> s;

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::string tmp;
        std::cin >> tmp;
        if(!s.count(tmp)) s.insert(tmp);
    }

    for(auto i: s) std::cout << i << "\n";
}