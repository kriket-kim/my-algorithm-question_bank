//greedy
#include <iostream>
#include <vector>

std::vector<int> coins;

int main(){
    int n, targ;
    std::cin >> n >> targ;

    coins.resize(n);
    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }    

    int idx = n -1, cnt = 0;
    while(targ != 0){
        if(idx < 0){
            cnt = -1;
            break;
        }
        else if(targ < coins[idx]) {
            idx--;
            continue;
        }
        else if (targ >= coins[idx]){
            targ -= coins[idx];
            cnt++;
        }
    }
    std::cout << cnt;
}