#include <iostream>
#include <stack>

std::stack<int> stack;

int main() {
    int n; std::cin >> n;

    for(int i = 0; i < n; i++){
        int t; std::cin >> t;

        if(t == 0){
            stack.pop();
        }
        else stack.push(t);
    }

    long long acc = 0;
    while(!stack.empty()){
        acc += stack.top();
        stack.pop();
    }
    std::cout << acc;
}