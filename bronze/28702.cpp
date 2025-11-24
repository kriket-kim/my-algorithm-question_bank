#include <iostream>
#include <string>

bool isn(std::string a){
    return a[0] >= '0'&& a[0] <= '9'; 
}
bool isf(std::string a) {
    return a == "Fizz";
}
bool isb(std::string a){
    return a == "Buzz";
}
bool isfb(std::string a){
    return a == "FizzBuzz";
}

int main() {
    std::string a, b, c;
    std::cin >> a >> b >> c;

    //n n f n
    //n n f b
    if(isn(a) && isn(b) && isf(c)){
        int res = std::stoi(b) + 2;
        if(res%5 == 0) std::cout << "Buzz";
        else std::cout << res;
    }  
    //n n fb n
    else if (isn(a) && isn(b) && isfb(c)){
        std::cout << std::stoi(b) + 2;
    }
    //n f n b
    //n f n n 
    else if (isn(a) && isf(b) && isn(c)){
        int res = std::stoi(c) + 1;
        if(res%5 == 0) std::cout << "Buzz";
        else std::cout << res;
    }
    //n f b n
    else if (isn(a) && isf(b) && isb(c)){
        std::cout << std::stoi(a) + 3;
    }
    //n b f n
    else if (isn(a) && isb(b) && isf(c)){
        std::cout << std::stoi(a) + 3;
    }
    //n fb n n
    else if (isn(a) && isfb(b) && isn(c)){
        std::cout << std::stoi(c) + 1;
    }
    //f n b f
    else if (isf(a) && isn(b) && isb(c)){
        std::cout << "Fizz";
    }
    //f n n f
    //f n n fb
    else if (isf(a) && isn(b) && isn(c)){
        int res = std::stoi(c) + 1;
        if(res%15 == 0) std::cout << "FizzBuzz";
        else std::cout << "Fizz";
    }
    //f b n f
    else if (isf(a) && isb(b) && isn(c)){
        std::cout << "Fizz";
    }
    //b f n n
    else if (isb(a) && isf(b) && isn(c)){
        std::cout << std::stoi(c) + 1;
    }
    //b n f n
    else if (isb(a) && isn(b) && isf(c)){
        std::cout << std::stoi(b) + 2;
    }
    //fb n n f
    else if (isfb(a) && isn(b) && isn(c)){
        std::cout << "Fizz";
    }
}