#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> cards;
std::vector<int> visited;

int n, m, max = 0;

void dfs(int cnt, int idx, int acc) {
    if(acc > m) return;

    if(cnt == 3) {
        if(acc <= m) max = std::max(max, acc);
        return;
    }

    for(int i = idx; i < n; i++){
        if(visited[i]) continue;

        visited[i] = 1;
        dfs(cnt + 1, i + 1, acc + cards[i]);
        visited[i] = 0;
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;

    cards.resize(n, 0);
    visited.resize(n, 0);
    for(int i = 0; i < n; i++){
        int tmp;
        std::cin >> cards[i];
    }
    //dfs(0,0, 0);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j +1 ; k < n; k++){
                int sum = cards[i] + cards[j] + cards[k];
                if(sum <= m) max = std::max(max, cards[i] + cards[j] + cards[k]);
            }
        }
    }

    std::cout << max << "\n";
}