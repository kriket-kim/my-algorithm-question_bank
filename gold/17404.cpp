#include <iostream>
#include <algorithm>

int arr[1000][3];
int cur[1000][3];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> arr[i][j];
        }
    }
    int min = 21e8;
    for(int st = 0; st < 3; st++){
        //첫 집을 고정해놓고 풀기?
        cur[0][st] = arr[0][st];
        //st = 0 -> 1, 2
        //st = 1 -> 1, 0
        //st = 2 -> 0, 1
        cur[0][(st+1) % 3] = cur[0][(st +2) % 3] = 10e8;
        
        for(int i = 1; i < n; i++){
            cur[i][0] = arr[i][0] + std::min({cur[i-1][1], cur[i-1][2]});
            cur[i][1] = arr[i][1] + std::min({cur[i-1][0], cur[i-1][2]});
            cur[i][2] = arr[i][2] + std::min({cur[i-1][0], cur[i-1][1]});
        }
        min = std::min({min, cur[n-1][(st+1) % 3], cur[n-1][(st+2) % 3]});
    }
    std::cout << min;
}