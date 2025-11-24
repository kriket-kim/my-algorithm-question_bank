#include <iostream>
#include <string>

int main() {
    std::string t;
    while(true){
        std::cin >> t;
        if(t == "0") break;
        int flag = 1;
        for(int i = 0; i < t.size() / 2; i++){
            if(t[i] != t[t.size() - 1 - i]){
                flag = 0;
                break;
            }
        }
        if(flag) std::cout << "yes\n";
        else std::cout << "no\n";
    }

}