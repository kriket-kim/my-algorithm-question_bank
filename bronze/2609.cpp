#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    int large, small;
    if(a >= b) {
        large = a;
        small =b;
    } 
    else {
        small = a;
        large = b;
    }
    int r = large % small;
    large = small;
    small = r;
    while(r != 0){
        r = large % small;
        large = small;
        small = r; 
    }
    std::cout << large << "\n" << (a * b) / large;
    return 0;
}