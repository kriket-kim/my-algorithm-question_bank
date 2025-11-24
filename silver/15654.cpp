#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> nums, visited, arr;
int n, m;

void dfs(int idx){
    if(idx == m) {
        for(int i = 0; i < m; i++) std::cout << arr[i] << " ";
        std::cout << "\n";

        return;
    }

    for(int i = 0; i< n; i++){
        if(visited[i]) continue;

        visited[i] = 1;
        arr[idx] = nums[i];
        dfs(idx + 1);
        visited[i] = 0;
    }
}

int main() {
    std::cin >> n >> m;

    visited.resize(n);
    nums.resize(n);
    arr.resize(n);

    for(int i = 0; i < n; i++) std::cin >> nums[i];
    std::sort(nums.begin(), nums.end());

    dfs(0);
}