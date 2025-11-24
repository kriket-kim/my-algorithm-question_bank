#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int sol = 0;
    for(int i = 1; i <= n; i++){
        int cpy = i;
        int digitsum = 0;
        while(cpy != 0){
            digitsum += cpy%10;
            cpy /= 10; 
        }
        if(i + digitsum == n){
            sol = i;
            break;
        }
    }

    std::cout << sol << "\n";
}