#include <iostream>
#include <queue>

std::queue<int> q;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    int cnt = 0;
    std::cout << "<";
    while(!q.empty()){
        if(++cnt == k){
            std::cout << q.front();
            if(q.size()!=1) std::cout << ", ";
            q.pop();
            cnt = 0;
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    std::cout << ">";
}