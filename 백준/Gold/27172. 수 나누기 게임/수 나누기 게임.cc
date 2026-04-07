#include <iostream>
#include <vector>

std::vector<int> cands;
int cand[1000001];
int score[1000001];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, max;
    max = 1;
    std::cin >> n;
    cands.resize(n);
    for(int i = 0; i < n; i++){
        std::cin >> cands[i];
        cand[cands[i]] = 1;
        max = std::max(max, cands[i]);
    }

    for(auto i: cands) {
        for(int j = i*2; j <= max; j+= i){
            if(!cand[j]) continue;
            //std::cout << i << ":"<< j << "\n" ;

            score[i]++;
            score[j]--;
        }
    }

    for(auto i: cands){
        std::cout << score[i] << " ";
    }
}