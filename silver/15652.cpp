#include <iostream>
int n, m;
    
int arr[9];
int visited[9];

void dfs(int idx, int val){
    if(idx == m) {
        for(int i = 0; i < m; i++) std::cout << arr[i] << " ";
        std::cout << "\n";
        return;
    }

    for(int i = val; i <= n; i++){
        arr[idx] = i;
        dfs(idx+1, i);
    }
}

int main() {
    std::cin >> n >> m;
    
    dfs(0, 1);
}