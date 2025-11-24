#include <iostream>
#include <string>

int storage = 0;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::string cmd;
    int t;
    for(int i = 0; i < n; i++){
        std::cin >> cmd;

        if(cmd == "all") storage = 0b11111111111111111111;
        else if (cmd == "empty") storage = 0;
        else if (cmd == "add"){
            std::cin >> t;
            storage |= (1<< (t-1));
        }
        else if (cmd == "remove") {
            std::cin >> t;
            storage &= ~(1 << (t-1));
        }
        else if (cmd == "check") {
            std::cin >> t;
            std::cout << (bool)(storage & (1 << (t-1))) << "\n";
        }
        else if (cmd == "toggle") {
            std::cin >> t;
            storage ^= (1 << (t-1));
        }
    }
}