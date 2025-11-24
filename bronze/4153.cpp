#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    while(true){
        std::cin >> a >> b >> c;
        int sum = 0;
        if( a== 0 && b == 0 && c == 0){
            break;
        }
        else if(a > b && a > c){
            sum = a*a - b*b - c*c;
        } else if (b > a && b > c){
            sum = b*b - a*a - c*c;
        } else if (c > a && c > b){
            sum = c*c - a*a - b*b;
        }
        if(sum == 0){
            std::cout << "right\n"; 
        }
        else {
            std::cout << "wrong\n";
        }
    }
}