#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int s, n, k, r1, r2, c1, c2;
int st, ed;

int arr[50][50];

void fill(int y, int x, int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            int cy = y + i;
            int cx = x + j;
            if(cy >= r1 && cy <= r2 && cx >= c1 && cx <= c2){
                arr[cy-r1][cx-c1] = 1;
            } 
        }
    }
}

void call(int y, int x, int length){
    if(length == 1) return;

    int reduced = length / n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i >= st && i < ed && j >= st && j < ed){
                if(y > r2 || x > c2) continue;
                if(y + (i+1) * reduced < r1 || x + (j+1) * reduced < c1) continue;

                fill(y + i * reduced, x + j*reduced, reduced);
            }      
            else call(y + i*reduced, x + j*reduced, reduced);
        }
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
   
    int size = std::pow(n, s);
    st = (n - k) /2;
    ed = st + k;
    call(0, 0, size);

    for(int i = 0; i <= r2 - r1; i++){
        for(int j = 0; j <= c2 - c1; j++){
            std::cout << arr[i][j];
        }
        std::cout << "\n";
    }
}