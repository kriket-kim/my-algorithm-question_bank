#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int n, m;

std::set<std::vector<int>> set;

std::vector<int> arr, num, visited;

void dfs(int idx, int val){
    if(idx == m){
        std::vector<int> s;
        for(int i = 0; i < m; i++){
            s.push_back(arr[i]);
        }
        if(!set.count(s)) set.insert(s);
        return;
    }

    for(int i = val; i < n; i++){
        arr[idx] = num[i];
        dfs(idx + 1, i);
    }
}

int main() {
    std::cin >> n >> m;

    arr.resize(n);
    num.resize(n);
    visited.resize(n);

    for(int i = 0; i < n; i++){
        std::cin >> num[i];
    }
    std::sort(num.begin(), num.end());

    dfs(0, 0);
    for(auto i: set) {
        for(int j = 0; j < m; j++) {
            std::cout << i[j] << " ";
        }
        std::cout << "\n";
    }
}