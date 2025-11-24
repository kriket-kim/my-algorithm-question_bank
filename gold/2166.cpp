//geometry, math
//https://darkpgmr.tistory.com/86
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<std::pair<int,int>> coords;

int main() {
    int n;
    std::cin >> n;
    coords.resize(n+1);

    for(int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;

        coords[i] = {a,b};
    }
    coords[n] = coords[0];

    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += ((double) coords[i].first * coords[i+1].second);
        sum -= ((double) coords[i+1].first * coords[i].second);
    }
    sum /= 2;

    std::cout <<std::fixed << std::setprecision(1)<< std::abs(sum) << "\n";

}