#include <iostream>

int solutions[100000];

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n ;i++){
        std::cin >> solutions[i];
    }
    int l = 0, r = n-1;
    
    int absmin = std::abs(solutions[l] + solutions[r]);
    int cand1 = 0, cand2 = n-1;

    while(l < r){
        int cur = solutions[l] + solutions[r];
        
        if(std::abs(cur) < absmin) {
            absmin = std::abs(cur);
            cand1 = l;
            cand2 = r;
        }

        if(cur < 0){
            l++;
        }
        else{
            r--;
        }
        
    }
    std::cout << solutions[cand1] << " " << solutions[cand2];
}