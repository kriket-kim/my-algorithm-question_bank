#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> times;

int main(){
    int n; 
    std::cin >>n ;
    times.resize(n);
    for(int i =0; i < n; i++){
        std::cin >> times[i];
    }
    std::sort(times.begin(), times.end());

    int total =0;
    for(int i = 0; i < n; i++){
        total += times[i] * (n-i);
    }
    std::cout << total;
}