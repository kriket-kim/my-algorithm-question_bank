#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> vec;
std::vector<long long> cands;
int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++){
        std::cin >> vec[i];
    }    

    std::sort(vec.begin(), vec.end());

    long long min = 40e8;

    for(int i = 0; i < n; i++){
        long long cur = vec[i];

        int l = i + 1, r = n-1;
        while(l < r){
            if(min > std::abs(vec[l] + vec[r] + cur)){
                min = std::abs(vec[l] + vec[r] + cur);
                cands = {cur, vec[l], vec[r]};
            }

            if(vec[l] + vec[r] + cur < 0){
                l += 1;
            }
            else{
                r -= 1;
            }
        }
    }
    for(auto i: cands) std::cout << i << " ";
}