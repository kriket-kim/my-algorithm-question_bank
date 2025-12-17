#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::pair<int,int>> vec;
std::vector<std::pair<int,int>> lis;

int binsearch(int left, int right, std::pair<int,int> targ){
    int mid;

    while(left < right){
        mid = (left + right) / 2;
        if(lis[mid].first < targ.first && lis[mid].second < targ.second){
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return right;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    lis = std::vector<std::pair<int,int>>(n, {0,0});
    vec.reserve(n);

    for(int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        vec.emplace_back(a,b);
    }
    std::sort(vec.begin(), vec.end());

    int i = 1, j = 0;
    lis[0] = vec[0];

    while(i < n) {
        if(lis[j].first < vec[i].first && lis[j].second < vec[i].second) {
            lis[j+1] = vec[i];
            j += 1;
        }
        else {
            int idx = binsearch(0, j, vec[i]);
            lis[idx] = vec[i];
        }

        i += 1;
    }
    std::cout << n - (j+1) << "\n";
}