//union-Find, Geometry

//Learnt: CCW, cross-product, built-in comparator of std::pair
#include <iostream>
#include <cstring>
#include <unordered_map>

struct Line {
    int x1;
    int y1;
    int x2;
    int y2;
} lines[3000];

int parent[3000], n;

int find(int node){
    if(parent[node] == node) return node;

    return parent[node] = find(parent[node]);
}

void setUnion(int a, int b){
    int p1 = find(a);
    int p2 = find(b);

    if(p1 == p2) return;

    if(p1 < p2) parent[p2] = p1;
    else parent[p1] = p2;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    long long ret = (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1);
    if(ret < 0) return -1;
    else if (ret == 0) return 0;
    else return 1;
}

bool intersection(struct Line a, struct Line b){
    int abc = ccw(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
    int abd = ccw(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
    int cda = ccw(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
    int cdb = ccw(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);

    if(abc * abd <= 0 && cda * cdb <= 0){
        if(abc * abd == 0 && cda * cdb == 0){
            std::pair<int, int> p1 = {a.x1, a.y1};
            std::pair<int, int> p2 = {a.x2, a.y2};
            std::pair<int, int> p3 = {b.x1, b.y1};
            std::pair<int, int> p4 = {b.x2, b.y2};
            //check colinear
            if(p1 > p2) std::swap(p1, p2);
            if(p3 > p4) std::swap(p3, p4);

            return p1 <= p4 && p3 <= p2;
        }
        return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++) parent[i] = i;

    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = {x1, y1, x2, y2};
    }    

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            bool in_group = intersection(lines[i], lines[j]);
            if(in_group){
                setUnion(i, j);
            }
        }
    }

    std::unordered_map<int,int> map;
    for(int i = 0; i < n; i++){
        map[find(i)]++;
    }
    int freq = 0;
    for(auto i: map){
        if(freq < i.second) freq = i.second;
    }
    std::cout << map.size() << "\n" << freq;
}