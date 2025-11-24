#include <iostream>
#include <string>
#include <algorithm>

std::string w = "WBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBW";
std::string b = "BWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWB";

char map[50][50];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> map[i][j];
        }
    }

    int min_cnt = 21e8;
    for(int i = 0; i <= n-8; i++){
        for(int j = 0; j <= m-8; j++){
            int c_w = 0;
            int c_b = 0;
            for(int k = 0; k < 64; k++){
                int ny = k / 8;
                int nx = k % 8;
                if(map[i + ny][j + nx] != w[k]) c_w++;
                if(map[i + ny][j + nx] != b[k]) c_b++;
            }
            min_cnt = std::min(min_cnt, c_w);
            min_cnt = std::min(min_cnt, c_b);
        }
    }

    std::cout << min_cnt << "\n";
}