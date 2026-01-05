#include <iostream>
#include <queue>
#include <algorithm>

int map[100001];
std::queue<int> q;

int main() {
    std::fill(map, map + 100001, 1e9);
    int n, k;
    std::cin >> n >> k;

    q.push(n);
    map[n] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int next = cur - 1;
        if(next >= 0 && next < 100001 && map[next] > map[cur] + 1 ){
            map[next] = map[cur] + 1;
            q.push(next);
        }
        next = cur + 1;
        if(next >= 0 && next < 100001 && map[next] > map[cur] + 1){
            map[next] = map[cur] + 1;
            q.push(next);
        }
        next = cur * 2;
        if(next >= 0 && next < 100001 && map[next] > map[cur]){
            map[next] = map[cur];
            q.push(next);
        }
    }

    std::cout << map[k];
}