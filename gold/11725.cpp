//graph search
#include <iostream>
#include <vector>

std::vector<std::vector<int>> nodes;
std::vector<int> parents;

void dfs(int parent){
    for(int i = 0; i < nodes[parent].size(); i++){
        if(parents[nodes[parent][i]] != -1) continue;

        parents[nodes[parent][i]] = parent;
        dfs(nodes[parent][i]);
    }
}

int main() {
    int n;
    std::cin >> n;
    nodes.resize(n);
    parents.resize(n, -1);

    for(int i = 0; i < n-1; i++){
        int parent, child;
        std::cin >> parent >> child;
        nodes[parent-1].push_back(child-1);
        nodes[child-1].push_back(parent-1);
    }
    parents[0] = 0;
    dfs(0);

    for(int i = 1; i < n; i++){
        std::cout << parents[i]+1 << "\n";
    }
}