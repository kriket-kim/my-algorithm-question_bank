#include <iostream>
#include <map>

std::map<int,int> map;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;
    for(int dt = 0; dt < t; dt++){
        map.clear();

        int n;
        std::cin >> n;

        for(int i = 0; i < n; i++){
            char cmd;
            int num;
            std::cin >> cmd >> num;

            if(cmd == 'I'){
                map[num]++;
            }
            else if(cmd == 'D') {
                if(map.size() == 0) continue;
                else if (num == 1){
                    if(map.rbegin()->second > 1) map.rbegin()->second--;
                    else map.erase(map.rbegin()->first);
                }
                else {
                    if(map.begin()->second > 1) map.begin()->second--;
                    else map.erase(map.begin()->first);   
                }
            }
        }

        if(map.size() == 0) std::cout << "EMPTY\n";
        else std::cout << map.rbegin()->first << " " << map.begin()->first << "\n";
    }    
}