#include <iostream>

int seq[2001];
int arr[2001][2001];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++){
        std::cin >> seq[i];
        arr[i][i] = 1;
    }

    for(int j = 1; j <= n-1; j++){
        if(seq[j] == seq[j+1]) arr[j][j+1] = 1;
    }

    for(int i = 2; i < n; i++){
        for(int j = 1; j <= n-i; j++){
            if(seq[j] == seq[j+i] && arr[j+1][j+i-1]){
                arr[j][j+i] = 1;
            }
        }
    }


    int m;
    std::cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        std::cout << arr[a][b] << "\n";
    }
}