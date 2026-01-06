#include <iostream>
#include <algorithm>

//v1 = vector using p2 -p1, v2 = p3 - 1
//then outer product is determinant of v1 and v2
int ccw(std::pair<long long, long long> p1, std::pair<long long, long long> p2, std::pair<long long, long long> p3){
    long long ret = (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
    if(ret < 0) return -1;
    if (ret == 0) return 0;
    return 1;
}

bool intersect(){
    std::pair<long long, long long> a, b, c, d;
    std::cin >> a.first >> a.second >> b.first >> b.second;
    std::cin >> c.first >> c.second >> d.first >> d.second;
    
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);

    //if two line segments are on same line,
    if(abc * abd == 0 && cda*cdb == 0){
        if(a > b) std::swap(a, b);
        if(c > d) std::swap(c, d);
        //check intersection by size
        return (b >= c && d >= a);
    }
    return (abc * abd <= 0 && cda * cdb <= 0);
}

int main() {
    if(intersect()){
        std::cout << 1 << "\n";
    }
    else {
        std::cout << 0 << "\n";
    }

}