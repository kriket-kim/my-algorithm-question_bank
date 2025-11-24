#include <iostream>

int s, n, k, r1, r2, c1, c2;

int getColor(int time, int y, int x){
    if(time ==0 ) return 0;

    int length = 1;
    for(int i = 0; i < time - 1; i++){
        length *= n;
    }

    int st = (n - k) / 2;
    int ed = (n + k) / 2;

    int scaled_y = y / length;
    int scaled_x = x / length;

    if(scaled_y >= st && scaled_y < ed && scaled_x >= st && scaled_x < ed){
        return 1;
    }

    return getColor(time - 1, y % length, x % length);
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    for(int i = r1; i <= r2; i++){
        for(int j = c1; j <=c2; j++) {
            std::cout << getColor(s, i, j);
        }
        std::cout << "\n";
    }
}