#include <iostream>
#include <queue>
#include <cmath>

struct comp{
    bool operator()(int a, int b) const{
        if(std::abs(a) == std::abs(b)) {
            return a > b;
        }
        return std::abs(a) > std::abs(b);
    }
};

std::priority_queue<int, std::vector<int>, comp> pq;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        int t; std::cin >> t;
        if(t != 0){
            pq.push(t);
        }
        else {
            if(pq.empty()) std::cout << "0\n";
            else{
                std::cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}