#include <iostream>
#include <unordered_map>
#include <algorithm>

int a[1001], b[1001];
std::unordered_map<long long, long long> map_a, map_b;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int t, n, m;
    std::cin >> t;

    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] += a[i-1];
    }
    std::cin >> m;
    for(int i = 1; i <= m; i++){
        std::cin >> b[i];
        b[i] += b[i-1];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j<= n; j++){
            map_a[a[j] - a[i-1]]++;
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = i; j<= m; j++){
            map_b[b[j]-b[i-1]]++;
        }
    }

    long long acc = 0;
    for(auto a_i: map_a){
        if(map_b.find(t-a_i.first) != map_b.end()) 
            acc += map_b[t - a_i.first] * a_i.second;
    }

    std::cout << acc;
}