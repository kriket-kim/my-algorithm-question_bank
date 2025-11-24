#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int cnt = 0;
    for(int i = n; i >= 1; i--){
        int cur = i;
        while(cur % 5 == 0){
            cur /= 5;
            cnt++;
        }
    }
    std::cout << cnt;
}