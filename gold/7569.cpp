#include <iostream>
#include <queue>

struct pos{
    int z;
    int y;
    int x;
};

int dy[6] = {0, -1, 0, 1, 0, 0};
int dx[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int box[100][100][100];

std::queue<struct pos> q;

void print(int m, int n, int h){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                std::cout << box[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

int main() {
    int m, n, h;
    std::cin >> m >> n >> h;
    
    int nripe = 0;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                std::cin >> box[i][j][k];
                if(box[i][j][k] == 0) nripe++;
                if(box[i][j][k] == 1) q.push({i,j,k});
            }
        }
    }

    int time = 0;
    while(true){
        if(nripe == 0){
            break;
        }
        
        int cur_size = q.size();
        if (cur_size == 0){
            time = -1;
            break;
        }

        for(int i = 0; i < cur_size; i++){
            auto cur_pos = q.front();
            q.pop();
            for(int j = 0; j < 6; j++){
                int nx = cur_pos.x + dx[j];
                int ny = cur_pos.y + dy[j];
                int nz = cur_pos.z + dz[j];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
                if(box[nz][ny][nx] == -1 || box[nz][ny][nx] == 1) continue;

                nripe--;
                box[nz][ny][nx] = 1;
                q.push({nz,ny,nx});
            }
        }
        time++;
        //print(m, n, h);
    }
    std::cout << time;
}