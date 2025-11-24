#include <iostream>
#include <queue>

int box[1000][1000];
std::queue<std::pair<int,int>> q;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void print(int m, int n) {
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n ; j++){
            std::cout << box[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int m, n; std::cin >> n >> m;
    int cnt = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cin >> box[i][j];
            if(box[i][j] == 1) q.push({i,j});
            if(box[i][j] == 0) cnt++;
        }
    }

    int day = 0;
    while(true){
        if(cnt == 0) {
            break;
        }
        
        int cur_len = q.size();
        if(cnt != 0 && cur_len == 0) {
            std::cout << "-1";
            return 0;
        }
        
        for(int i = 0; i < cur_len; i++){
            auto cur = q.front();
            q.pop();

            for(int j = 0; j < 4; j++){
                int ny = cur.first + dy[j];
                int nx = cur.second + dx[j];

                if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                if(box[ny][nx] != 0) continue;

                cnt--;
                box[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
        day++;
    }
    std::cout << day;
}