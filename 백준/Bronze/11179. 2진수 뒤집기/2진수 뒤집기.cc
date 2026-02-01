#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    int t = 0;
    while(n != 0){
        t = t << 1;
        if (n & 0b1){
            t += 1;
        } 
        n = n >> 1;
    }
    std::cout << t;
}