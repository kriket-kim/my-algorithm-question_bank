#include <string>
#include <iostream>
#include <stack>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    while(true){
        std::string s;
        std::getline(std::cin, s);
       
        std::stack<char> st;

        if(s == "."){
            break;
        }
        bool flag = true;

        for(int i = 0; i < s.length() ;i++){
            if(s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            else if(s[i] == ')') {
                if(st.empty() || st.top() != '(') {
                    flag = false;
                    break;
                }
                st.pop();
            }
            else if (s[i] == ']') {
                if(st.empty() || st.top() != '[') {
                    flag = false;
                    break;
                }
                st.pop();
            }
        }

        if(!st.empty()) flag = false;

        if(flag) std::cout << "yes\n";
        else std::cout << "no\n";
    }    

}