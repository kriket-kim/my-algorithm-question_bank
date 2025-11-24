#include <iostream>

char input[51];

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int l;
    std::cin >> l >> input;

    long long r = 1;
    long long m = 1234567891;

    long long sum = 0;

    for(int i = 0; i < l; i++){
        sum += ( (input[i] - 'a' + 1) * r );
        sum %= m;

        r *= 31;
        r %= m;
    }
    std::cout << sum << "\n";
}