//tri-state dfs for cycle detection
#include <iostream>

//-1: not visited, 0: active, 1: in a path
int points[100001], state[100001];
int n, t, acc;

void dfs(int cur){
    state[cur] = 0;
    int next = points[cur];
    if(state[next] == 0){// cycle found
        //count points part of cycle
        int count = 1;
        for(int i = next; i != cur; i = points[i]) count++;
        acc += count;
    } 
    else if(state[next] == -1){
        dfs(next);
    }

    state[cur] = 1;
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> t;
    for(int dt = 0; dt < t; dt++){
        std::cin >> n;
        std::fill(state, state + 100001, -1);
        acc = 0;

        for(int i = 1; i <= n; i++){
            std::cin >> points[i];
        }

        for(int i = 1 ; i <= n; i++){
            if(state[i] == -1) dfs(i);
        }
        std::cout << n - acc << "\n";
    }
}