#include <iostream>

long long n;

long long matrix[2][2] = {{1,1}, {1,0}};
long long res;

void multiply(long long mat1[2][2], long long mat2[2][2]) {
    long long tmp[2][2];

    tmp[0][0] = (mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0]) % 1000000007;
    tmp[0][1] = (mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1]) % 1000000007;
    tmp[1][0] = (mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0]) % 1000000007;
    tmp[1][1] = (mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1]) % 1000000007;

    mat1[0][0] = tmp[0][0];
    mat1[0][1] = tmp[0][1];
    mat1[1][0] = tmp[1][0];
    mat1[1][1] = tmp[1][1];
}

void power(long long idx) {

    long long expo = idx;

    long long ans[2][2] = {{1,0}, {0,1}};

    while(expo) {
        if(expo & 1) multiply(ans, matrix);
        multiply(matrix,matrix);
        expo >>= 1;
    }

    res = ans[0][0] % 1000000007;
}

int main() {
    std::cin >> n;

    if(n == 0 || n == 1) {
        std::cout << 1 << "\n";
        return 0;
    }

    power(n-1);    

    std::cout << res;
}