#include <iostream>
#include <map>
#include <string>
#include <vector>

int main (){
    int n;
    std::cin >> n;

    std::map<int, std::vector<std::string>> m;

    for(int i = 0; i < n; i++){
        int age;
        std::string name;
        
        std::cin >> age >> name;

        m[age].push_back(name);
    }

    for(auto i: m){
        for(auto j: i.second){
            std::cout << i.first << " " << j << "\n";
        }
    }
}