#include <iostream>
#include <stack>
#include <string>

int main() {
    int n; std::cin >> n;

    for(int i = 0;i < n; i++){
        std::stack<char> stack;
        std::string s; std::cin >> s;
        bool flag = true;

        for(int j = 0; j < s.length(); j++){
            if(s[j] == '(') stack.push('(');
            else if(s[j] == ')' && stack.empty()) {
                flag = false;
                break;
            }     
            else if(stack.top() == '(' && s[j] == ')'){
                stack.pop();
            } 
        }

        if(!stack.empty()) flag = false;

        if(flag) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}