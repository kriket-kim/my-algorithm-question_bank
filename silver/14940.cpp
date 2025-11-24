#include <iostream>
#include <queue>
#include <cstring>

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int map[1000][1000];
int dist[1000][1000];


std::queue<std::pair<int,int>> q;

int main() {
    memset(dist, -1, sizeof(dist));
    int n, m;

    std::cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> map[i][j];
            if(map[i][j] == 2){
                q.push({i,j});
                dist[i][j] = 0;
            }
            if(map[i][j] == 0) dist[i][j] = 0;
        }
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx>=m) continue;
            if(dist[ny][nx] != -1) continue;
    
            dist[ny][nx] = dist[cur.first][cur.second] + 1;
            q.push({ny, nx});            
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << dist[i][j] << " ";
        }
        std::cout << "\n";
    }
}