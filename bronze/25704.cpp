#include <iostream>
#include <algorithm>

int main() {
    int n, p;
    std::cin >> n >> p;

    int discount = 0;
    if(n>= 20){
        discount = std::max(discount, (int)(p*0.25));
    }
    if(n>=15){
        discount = std::max(discount, 2000);
    }
    if(n>=10){
        discount = std::max(discount, (int)(p*0.1));
    }
    if(n>=5){
        discount = std::max(discount, 500);
    }

    std::cout << std::max(0, p-discount)<< "\n";
}