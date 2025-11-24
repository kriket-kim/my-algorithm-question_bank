#include <iostream>
#include <cstring>

int nck[11][11];

int bin(int n, int k){
    if(k == 0 || n == k) return 1;

    int& ret = nck[n][k];
    if(ret != -1) return ret;

    return ret = bin(n-1, k-1) + bin(n-1, k);
}

int main(){
    memset(nck, -1, sizeof(nck));
    int n, k;
    std::cin >> n >> k;

    std::cout << bin(n, k);

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            std::cout << nck[i][j] << " ";
        }
        std::cout << "\n";
    }
}