//Two Pointer
//For two pointer, they array needs to be incrementing
//here, as we are using the sum of subsequence, it is monotonically increasing, hence it works
//is using sliding window style two pointer 
#include <iostream>
int arr[100001];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n, s;
    std::cin >> n >> s;
    
    for(int i = 1; i <= n; i++){
        std::cin >> arr[i];
    }
    int left = 0, right = 0;
    int sum = 0, best = 21e8;    
        
    while(left <= n){
        //std::cout << sum << ":" << left << "-" << right << "\n";
        if(sum >= s){
            best = std::min(best, right - left+1);
            sum -= arr[left];
            
            left += 1;
        }
        else { 
            right += 1;
            sum += arr[right];
            
            if (right > n) break;
        }
    }
    if (best == 21e8) std::cout << "0";
    else std::cout << best;
}