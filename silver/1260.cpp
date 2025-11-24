#include <iostream>
#include <queue>
#include <cstring>

int n, m;

int map[1001][1001];
int visited[1001];

void dfs(int node){
    std::cout << node << " ";

    for(int i = 1; i <= n; i++){
        if(!map[node][i]) continue;
        if(visited[i]) continue;
        visited[i] = 1;
        dfs(i);
    }
}

int main() {
    int st;
    std::cin >> n >> m >> st;
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    visited[st] = 1;
    dfs(st);
    std::cout << "\n";
    memset(visited, 0, sizeof(visited));
       
    std::queue<int> q;
    visited[st] = 1;
    q.push(st);

    while(!q.empty()){
        int cur = q.front();
        std::cout << cur << " ";
        q.pop();
        for(int i = 1; i <= n; i++){
            if(!map[cur][i]) continue;
            if(visited[i]) continue;
            visited[i] = 1;
            q.push(i);
        }
    }
}