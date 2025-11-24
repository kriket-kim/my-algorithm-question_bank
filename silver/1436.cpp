#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    
    std::vector<std::string> vec;
    vec.resize(10001);
    
    int cnt = 0;
    vec[cnt] = "0";

    std::string tmp;
    for(int i = 666; i < 6660000; i++){
        tmp = std::to_string(i);
        if(tmp.find("666") != std::string::npos){
            vec[++cnt] = tmp;
        }
    
        if(cnt == n) break;
    }

    std::cout << vec[n];
}