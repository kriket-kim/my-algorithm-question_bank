//Fash exponentional

#include <iostream>
#include <algorithm>

int main() {
    long long a, b, c;  
    
    std::cin >> a >> b >> c;

    long long y = 1;
    while(b > 0) {
        if(b % 2) y = (a * y) % c;
        a = (a * a) % c;
        b = b >> 1;
    }

    std::cout << y;
}