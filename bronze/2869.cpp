#include <iostream>
int v, a, b;

int main() {
    std::cin >> a >> b >> v;

    int days = (v - b) / (a-b);
    int rem = (v - b) % (a-b);
    if (rem != 0) days += 1;
    std::cout << days << "\n";
}