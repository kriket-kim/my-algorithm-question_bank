#include <iostream>
#include <deque>
#include <string>

std::deque<int> dq;

int main() {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;

        if(s == "push"){
            int a; std::cin >> a;
            dq.push_back(a);
        }
        else if (s == "pop"){
            if(dq.size() == 0) std::cout << "-1\n";
            else {
                std::cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (s == "size"){
            std::cout << dq.size() << "\n";
        }
        else if (s == "empty") {
            std::cout << dq.empty() << "\n";
        }
        else if (s == "front") {
            if(dq.size() == 0) std::cout << "-1\n";
            else std::cout << dq.front() << "\n";
        }
        else if (s == "back") {
            if(dq.size() == 0) std::cout << "-1\n";
            else std::cout << dq.back() << "\n";
        }
    }
}