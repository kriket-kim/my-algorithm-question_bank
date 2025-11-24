#include <iostream>
#include <map>

std::map<long long, long long> map;

void dp(long long a, long long b){
    int cur = map[a]; 
    if(!map[2*a]) map[2*a] = __LONG_LONG_MAX__;
    if(!map[10*a + 1]) map[10*a + 1] = __LONG_LONG_MAX__;

    if(2 * a <= b && map[2*a] > cur + 1){
        map[2*a] = cur + 1;
        dp(2*a, b);
    }
    if((a*10) + 1 <= b && map[a*10 + 1] > cur+1){
        map[a*10 + 1] = cur + 1;
        dp(10*a + 1, b);
    }
}

int main()  {
    long long a, b;
    std::cin >> a >> b;
    map[a] = 1;
    dp(a, b);
    
    std::cout << (!map[b] ? -1 : map[b]);
}