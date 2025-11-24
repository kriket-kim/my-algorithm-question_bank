#include <iostream>
#include <algorithm>

//0,0 inherent
//x,y
std::pair<int,int> blocks[19][3] = {
    {{0,1}, {0,2}, {0,3}},
    {{1,0}, {2,0}, {3,0}},
    {{1,0}, {0,1}, {1,1}},
    {{0,1}, {0,2}, {1,2}},
    {{1,0}, {2,0}, {0,1}},
    {{1,0}, {1,1}, {1,2}},
    {{-2,1}, {-1,1}, {0,1}},
    {{0,1}, {0,2}, {-1,2}},
    {{0,1}, {1,1}, {2,1}},
    {{1,0}, {0,1}, {0,2}},
    {{1,0}, {2,0}, {2,1}},
    {{0,1}, {1,1}, {1,2}},
    {{1,0}, {-1,1}, {0,1}},
    {{-1,1}, {0,1}, {-1,2}},
    {{1,0}, {1,1}, {2,1}},
    {{-1,1}, {0,1}, {1,1}},
    {{-1,1}, {0,1}, {0,2}},
    {{0,1}, {1,1}, {0,2}},
    {{1,0}, {2,0}, {1,1}},
};
int map[500][500];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int n, m;
    std::cin >> n >> m;
    
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> map[i][j];
        }
    }
    int max = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cy = i;
            int cx = j;

            for(int type = 0; type < 19; type++){
                int score = map[cy][cx];
                int flag = true;

                for(int k = 0; k < 3; k++){
                    int dy = cy + blocks[type][k].second;
                    int dx = cx + blocks[type][k].first;
                    if(dy < 0 || dy >= n || dx < 0 || dx >= m) {
                        flag = false;
                        break;
                    }   
                    score += map[dy][dx];
                }
                if(flag) max = std::max(max, score);
            }
        }
    }

    std::cout << max;
}