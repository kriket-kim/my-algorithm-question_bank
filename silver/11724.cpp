#include <iostream>
#include <queue>

int n, m;

int map[1001][1001];
int visited[1001];

void bfs(int node){
    std::queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 1; i<= n; i++){
            if(visited[i]) continue;
            if(!map[cur][i]) continue;

            visited[i] = 1;
            q.push(i);
        }
    }

}

int main() {
    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;

        std::cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]) {
            bfs(i);
            cnt++;
        }
    }
    std::cout << cnt;
}