#include <iostream>
#include <stack>
#include <vector>

std::stack<int> st;
std::vector<char> vec;
int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    int cur = 1;

    for(int i = 0; i < n; i++){
        int tmp;
        std::cin >> tmp;
        
        if(tmp >= cur){
            while(tmp >= cur){
                st.push(cur++);
                vec.push_back('+');                
            }
            st.pop();
            vec.push_back('-');
        }
        else{
            if(st.top() == tmp){
                st.pop();
                vec.push_back('-');
            }
            else{
                std::cout << "NO";
                return 0;
            }
        }
    }
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << "\n";
    }
}