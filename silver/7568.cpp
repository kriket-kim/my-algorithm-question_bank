#include <iostream>
    
int w[55], h[55], n, rank[55];

int main(){
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> w[i] >> h[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(w[i] < w[j] && h[i] < h[j]){
                rank[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        std::cout << rank[i] +1 << " "; 
    }
}