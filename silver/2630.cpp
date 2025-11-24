#include <iostream>

int map[128][128];
int cnts[2];

void rec(int y, int x, int size){
    if(size == 1){
        cnts[map[y][x]]++;
        return;
    }
    //check for uniformity
    int base = map[y][x];
    bool flag = true;
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x+size; j++){
            if(base != map[i][j]){
                flag = false;
                goto out;
            }
        }
    }
    out:
    if(!flag){
        rec(y, x, size/2);
        rec(y, x + size/2, size/2);
        rec(y + size/2, x, size/2);
        rec(y + size/2, x + size/2, size/2);
    }
    else {
        cnts[base]++;
    }
}

int main() {
    int n; std::cin >>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin>>map[i][j];
        }
    }

    rec(0,0, n);
    std::cout << cnts[0] << "\n" << cnts[1];
}