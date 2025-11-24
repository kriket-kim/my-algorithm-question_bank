#include <iostream>
#include <cstring>

int n;

int arr[1000001];

void find(int n, int ops){
    if(n == 1){
        arr[1] = std::min(ops, arr[1]);
        return;
    }

    int& ret = arr[n];
    if(ret < ops) return;
    ret = ops;

    if(n%3 == 0 && n/3 >= 1) find(n/3 , ret+1);
    if(n%2 == 0 && n/2 >= 1) find(n/2 , ret+1);
    if(n-1 >= 1) find(n-1, ret+1);
}

int main() {
    for(int i = 1; i <= 1000000; i++) arr[i] = 21e8;
    std::cin >> n;
    
    if(n == 1){
        std::cout << 0;
        return 0;
    } 

    arr[n] = 0;
    if(n%3 == 0 && n/3 >= 1) find(n/3, 1);
    if(n%2 == 0 && n/2 >= 1) find(n/2, 1);
    if(n-1 >= 1) find(n-1, 1);

    std::cout << arr[1];    
}