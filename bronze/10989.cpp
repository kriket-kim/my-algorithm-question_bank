#include <map>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >>n;
    std::map<int,int> nums;
    for(int i = 0; i < n; i++){
        int tmp;
        std::cin >> tmp;
        nums[tmp]++;
    }
    for(auto i: nums){
        for(int j = 0; j < i.second; j++){
            std::cout << i.first << "\n";
        }
    }
}