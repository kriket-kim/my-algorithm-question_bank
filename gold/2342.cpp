#include <iostream>
#include <cstring>

int arr[100001][5][5];

//st, ed
int costs[5][5] = {
    {2'100'000'000, 2, 2, 2, 2}, //zero to others
    {2'100'000'000, 1, 3, 4, 3},
    {2'100'000'000, 3, 1, 3, 4},
    {2'100'000'000, 4, 3, 1, 3},
    {2'100'000'000, 3, 4, 3, 1}
};

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    memset(arr, 1<<7 - 1, sizeof(arr));
    int idx = 0;
    arr[idx++][0][0] = 0;
    int t;
    while(true){
        std::cin >> t;
        if(t == 0) break;

        for(int l = 0; l < 5; l++){            
            for(int r = 0; r < 5; r++){
                arr[idx][t][r] = std::min(arr[idx-1][l][r] + costs[l][t] ,arr[idx][t][r]);
                arr[idx][l][t] = std::min(arr[idx-1][l][r] + costs[r][t], arr[idx][l][t]);
            }
        }
        idx++;
    }
    int min = 0x7F7F7F7F;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            min = std::min(arr[idx-1][i][j], min);
        }
    }
    std::cout << min;
}