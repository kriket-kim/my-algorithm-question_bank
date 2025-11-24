#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int sizes[6];
    for(int i = 0; i < 6; i++){
        std::cin >> sizes[i];
    }
    int t, p;
    std::cin >> t >> p;
    
    int sum = 0;
    for(int i = 0; i < 6; i++){
        int q = sizes[i] / t;
        int r = sizes[i] % t;
        //std::cout << sizes[i] << "/" << t << "=" << q << ", " << r  << "\n";
        sum += q;
        if(r != 0) sum += 1;
    } 
    std::cout << sum << "\n";
    std::cout << n / p << " " << n % p << "\n";
}