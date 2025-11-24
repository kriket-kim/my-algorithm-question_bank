#include <iostream>

int n, m;

int arr[9];
int visited[9];

void dfs(int idx, int cur){
    if(idx == m) {
        for(int i = 0; i < m; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for(int i = cur; i <= n; i++){
        if(visited[i]) continue;

        arr[idx] = i;
        visited[i] = 1;
        dfs(idx + 1, i);
        visited[i] = 0;
    }
}

int main() {
    std::cin >> n >> m;

    dfs(0, 1);
}