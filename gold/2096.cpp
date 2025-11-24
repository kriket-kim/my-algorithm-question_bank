#include <iostream>
#include <algorithm>
#include <cstring>

int arr[3];

int mins[3];
int maxs[3];

int mintmp[3];
int maxtmp[3];

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> arr[j];
        }
        if(i == 0){
            for(int j = 0; j < 3; j++){
                mins[j] = mintmp[j] = maxs[j] = maxtmp[j] = arr[j];
            }
        }
        else {
            mins[0] = std::min(mintmp[0], mintmp[1]) + arr[0];
            mins[1] = std::min({mintmp[0], mintmp[1], mintmp[2]}) + arr[1];
            mins[2] = std::min(mintmp[1], mintmp[2]) + arr[2];
            
            maxs[0] = std::max(maxtmp[0], maxtmp[1]) + arr[0];
            maxs[1] = std::max({maxtmp[0], maxtmp[1], maxtmp[2]}) + arr[1];
            maxs[2] = std::max(maxtmp[1], maxtmp[2]) + arr[2];

            memcpy(maxtmp, maxs, sizeof(maxtmp));
            memcpy(mintmp, mins, sizeof(mintmp));
        }
    }
    std::cout << std::max({maxs[0], maxs[1], maxs[2]}) 
            << " " << std::min({mins[0], mins[1], mins[2]}) << "\n";    
}