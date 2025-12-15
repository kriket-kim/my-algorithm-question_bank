#include <iostream>
#include <queue>

struct Coord{
    int y;
    int x;
};

struct curRound{
    struct Coord cR;
    struct Coord cB;
    int round;
};

int n, m;
char map[10][10];
int visited[10][10][10][10];
std::queue<struct curRound> q;

int dy[4] = {0, 1, -1, 0};
int dx[4] = {-1, 0, 0, 1};

struct Coord roll(struct Coord c, int dir){
    struct Coord ed = {c.y, c.x};
    while(true){
        int ny = ed.y + dy[dir];
        int nx = ed.x + dx[dir];
        
        char next = map[ny][nx];
        if(next == '#') break;

        ed.y = ny;
        ed.x = nx;
        if(next == 'O') break;
    }
    return ed;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;
    
    struct Coord iR, iB;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> map[i][j];
            if(map[i][j] == 'R'){
                map[i][j] = '.';
                iR.y = i;
                iR.x = j;
            }
            if(map[i][j] == 'B'){
                map[i][j] = '.';
                iB.y = i;
                iB.x = j;
            }
        }
    }
    int min = 11;
    visited[iR.y][iR.x][iB.y][iB.x] = 1;
    q.push({iR, iB, 0});

    while(!q.empty()){
        struct curRound cur = q.front();
        q.pop();

        int nround = cur.round + 1;
        if(nround > 10) break; 
        //moving left
        //1. first choose which to move
        for(int i = 0; i < 4; i++){
            struct Coord nR = roll(cur.cR, i);
            struct Coord nB = roll(cur.cB, i);

            //check for exit conditions
            if(map[nB.y][nB.x] == 'O'){
                continue;
            }
            else if(map[nR.y][nR.x] == 'O' && map[nB.y][nB.x] != 'O'){
                visited[nR.y][nR.x][nB.y][nB.x] = 1;
                std::cout << nround;
                return 0;
            }
            
            if(nR.x == nB.x && nR.y == nB.y){
                //adjust position on overlap
                if(i == 0){ //left
                    if(cur.cR.x <= cur.cB.x) nB.x += 1;
                    else nR.x += 1; 
                }else if (i == 1){ //down
                    if(cur.cR.y <= cur.cB.y) nR.y -= 1;
                    else nB.y -= 1;
                }else if (i == 2){//up
                    if(cur.cR.y <= cur.cB.y) nB.y += 1;
                    else nR.y += 1;
                }else {//right
                    if(cur.cR.x <= cur.cB.x) nR.x -= 1;
                    else nB.x -= 1;
                }
            }
            if(visited[nR.y][nR.x][nB.y][nB.x]) continue;

            visited[nR.y][nR.x][nB.y][nB.x] = 1;
            q.push({nR, nB, nround});
        }
    }
    std::cout << "-1";
}