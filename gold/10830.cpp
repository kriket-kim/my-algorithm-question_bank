#include <iostream>
#include <vector>

class SquareMatrix {
    public: 
    int dim;
    int arr[5][5];

    SquareMatrix(){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                arr[i][j] = 0;
            }
        }
    }

    SquareMatrix(int n) {
        dim = n;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                arr[i][j] = 0;
            }
        }
    }

    SquareMatrix operator*(const SquareMatrix& b) const{
        SquareMatrix ret = SquareMatrix(dim);
        ret.dim = dim;
        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
                for(int k = 0; k < dim ;k++){
                    ret.arr[i][j] += arr[i][k] * b.arr[k][j];
                }
                ret.arr[i][j] %= 1000;
            }
        }
        return ret;
    }
};

SquareMatrix identity;

SquareMatrix pow(SquareMatrix a, long long b){
    if(b == 0) return identity;
    
    if(b % 2 == 1) return a * pow(a, b - 1);

    SquareMatrix half = pow(a, b/2);    
    
    return half * half;
}

int main() {
    int n;
    long long b;
    std::cin >> n >> b;

    identity = SquareMatrix(n);
    for(int i = 0; i < n; i++){
        identity.arr[i][i] = 1;
    }

    SquareMatrix orig = SquareMatrix(n);
    orig.dim = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> orig.arr[i][j];
            orig.arr[i][j] %= 1000;
        }
    }
    
    SquareMatrix sol = pow(orig, b);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << sol.arr[i][j]<< " ";
        }
        std::cout << "\n";
    }
}