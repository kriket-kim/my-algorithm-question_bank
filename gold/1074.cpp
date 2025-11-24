#include <iostream>
#include <cmath>

int n, r, c;

int rec(int size, int ty, int tx){
    if(size == 1) {
        if(ty == 0 && tx == 0){
            return 0;
        }
        else if (ty == 0 && tx == 1){
            return 1;
        }
        else if (ty == 1 && tx == 0){
            return 2;
        }
        else {
            return 3;
        }
    }

    int mid = std::pow(2, size-1);

    if(ty < mid && tx < mid){
        return rec(size-1, ty,tx);
    }else if (ty < mid && tx >= mid){
        return 1*(mid * mid) + rec(size-1, ty,tx - mid);
    }else if (ty >= mid && tx < mid){
        return 2*(mid * mid) + rec(size-1, ty-mid,tx);
    }else {
        return 3*(mid * mid) + rec(size-1, ty-mid,tx-mid);
    }
}

int main() {
    std::cin >> n >> r >> c;
    
    std::cout << rec(n, r, c);
}