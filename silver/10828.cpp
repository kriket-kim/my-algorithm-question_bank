#include <iostream>
#include <stack>
#include <string>

std::stack<int> stack;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::string cmd; std::cin >> cmd;

        if(cmd == "push") {
            int t; std::cin >> t;
            stack.push(t);
        } else if (cmd == "pop") {
            if(stack.empty()) std::cout << "-1\n";
            else {
                std::cout << stack.top() << "\n";
                stack.pop();
            }
        } else if (cmd == "size") {
            std::cout << stack.size() << "\n";
        } else if (cmd == "empty") {
            std::cout << stack.empty() << "\n";
        } else if (cmd == "top") {
            if(stack.empty()) std::cout << "-1\n";
            else std::cout << stack.top() << "\n";
        }
    }
}