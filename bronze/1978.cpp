#include <iostream>
#include <cstring>

int nums[1001];

int main() {
    memset(nums, 0, sizeof(nums));

    int n;
    std::cin >> n;
    
    nums[1] = 1;
    for(int i = 2; i < 1000; i++){
        for(int j = 2; i*j <= 1000; j++){
            nums[i*j] = 1;
        }
    }
    int cnt = 0;
    int tmp;
    for(int i = 0; i < n; i++){
        std::cin >> tmp;
        if(!nums[tmp]) cnt++;
    }
    std::cout << cnt << "\n";
}