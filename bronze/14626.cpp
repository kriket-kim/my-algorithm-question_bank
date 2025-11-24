#include <iostream>

char isbn[14];

int main() {
    int tgt_idx = 0;
    for(int i = 1; i <= 13; i++){
        std::cin >> isbn[i];
        if(isbn[i] == '*') tgt_idx = i;
    }
    
    int sum = 0;
    for(int i = 1; i <=12; i++){
        if(i == tgt_idx) continue;
        
        if(i % 2 == 0) sum += 3 * (isbn[i]-'0');
        else sum += (isbn[i] - '0');

    }
    if(tgt_idx == 13){
        std::cout << (10 - (sum%10))% 10;
    }
    else {
        int weight = (tgt_idx % 2 == 0 ? 3 : 1);
        for(int i = 0; i <= 9; i++){
            if((sum + (weight*i) + (isbn[13] - '0'))%10 == 0){
                std::cout << i << "\n";
                return 0;
            }
        }
    }
}