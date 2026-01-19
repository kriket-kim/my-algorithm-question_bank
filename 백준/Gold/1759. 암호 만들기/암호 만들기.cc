#include <iostream>
#include <algorithm>
#include <vector>

int l, c;
std::vector<char> cur;
std::vector<char> vec;

void find(int idx){
    if(cur.size()== l){
        int v = 0, nv = 0;
        for(int i = 0; i < l; i++){
            if( cur[i] == 'a' ||
                cur[i] == 'e' ||
                cur[i] == 'i' || 
                cur[i] == 'o' || 
                cur[i] =='u') v++;
            else nv++;
        }
        if(v >= 1 && nv >= 2){
            for(int i = 0; i < l; i++) std::cout << cur[i];
            std::cout << "\n";
        }
        return;
    }

    for(int i = idx; i < c; i++){
        cur.push_back(vec[i]);
        find(i+1);
        cur.pop_back();
    }
}


int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> l >> c;

    for(int i = 0; i < c; i++){
        char t;
        std::cin >> t;
        vec.push_back(t);
    }
    std::sort(vec.begin(), vec.end());

    find(0);
}