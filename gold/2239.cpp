#include <iostream>

int map[9][9];

bool finished = false;

void dfs(int idx){
    if(finished) return;

    if(idx == 81) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                std::cout << map[i][j];
            }
            std::cout << "\n";
        }
        finished = true;
        return;
    } 
    //std::cout << "idx: " << idx << "\n";
    
    int y = idx / 9;
    int x = idx % 9;
    
    if(map[y][x] != 0) dfs(idx + 1);
    else {
        for(int i = 1; i <= 9; i++){
            bool flag = true;
            //check vertical
            for(int dy = 0; dy < 9; dy++){
                if(dy == y) continue;
                if(map[dy][x] == i){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            //check horizontal
            for(int dx = 0; dx < 9; dx++){
                if(dx == x) continue;
                if(map[y][dx] == i){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            //check box
            int py = 3*(y/3);
            int px = 3*(x/3);
            for(int dy = 0; dy < 3; dy++){
                for(int dx = 0; dx < 3; dx++){
                    if(py+dy == y && px + dx == x) continue;

                    if(map[py + dy][px + dx] == i) {
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) continue;

            map[y][x] = i;
            dfs(idx + 1);
            map[y][x] = 0;
        }
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char c;
            std::cin >> c;
            map[i][j] = c - '0';
        }
    }

    dfs(0);
}