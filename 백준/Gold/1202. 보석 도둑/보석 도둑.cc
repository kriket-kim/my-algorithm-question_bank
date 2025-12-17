//Priority queue, Greedy
//Why it is greedy? Because we need to choose current maximum value gem in current gem pool.
//Why PQ? because we keep add gem to candidate pool, and retrieve best value.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

std::vector<int> bags;
std::vector<std::pair<int, int>> gems;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;
    bags.reserve(k);
    gems.reserve(n);

    for(int i = 0; i < n; i++){
        int m, v;
        std::cin >> m >> v;
        gems.push_back({m, v});
    }
    for(int j = 0; j < k; j++){
        int c;
        std::cin >> c;
        bags.push_back(c);
    }
    std::sort(gems.begin(),gems.end());
    std::sort(bags.begin(),bags.end());

//    for(auto i : gems) std::cout << i.first << " " << i.second << "\n";

    std::priority_queue<int> pq;
    int idx = 0;
    long long sum = 0;
    //starting from lightest bag,
    for(int i = 0; i < k; i++){
        //fint all jewels that fits in the bag
        for(; idx < n; idx++){
            //if current gem does not fit, break for current bag
            if(gems[idx].first > bags[i]) {
                break;
            }
            // std::cout << "pushing " << gems[idx].second << "\n";
            pq.push(gems[idx].second);
        }

        if(pq.empty()) continue;

        // std::cout << pq.top() << "\n";
        sum += pq.top();
        pq.pop();
    }
    
    std::cout << sum;
}