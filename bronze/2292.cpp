#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int acc = 1;
    int base = 0;
    while(true){
        acc += base * 6;
        if(n <= acc) break;
        base++;
    }
    std::cout << base + 1;
}