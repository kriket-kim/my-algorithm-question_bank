#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::map<int,int> map;
std::vector<int> vec;
std::unordered_map<int, int> umap;
int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    vec.resize(n);

    for(int i = 0; i < n; i++){
        std::cin >> vec[i];
        map[vec[i]]++;
    }
    
    int idx = 0;
    for(auto i: map){
        umap.insert({i.first, idx++});
    }
    for (auto i: vec){
        std::cout << umap[i] << " ";
    }
}