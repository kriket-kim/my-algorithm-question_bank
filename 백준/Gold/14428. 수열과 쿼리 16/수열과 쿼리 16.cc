#include <iostream>

int arr[100001];
std::pair<int,int> seq[400005];

std::pair<int,int> merge(const std::pair<int,int>& a, const std::pair<int,int>& b) {
    if(a.second < b.second) return a;
    if(a.second > b.second) return b;

    return (a.first < b.first) ? a : b;
}

void init(int idx, int left, int right){
    if(left == right){
        seq[idx].first = left;
        seq[idx].second = arr[left];
        return;
    }

    int mid = (left + right) / 2;

    init(2*idx, left, mid);
    init(2*idx + 1, mid+1, right);
    
    seq[idx] = merge(seq[2*idx], seq[2*idx+1]);
}

void update(int idx, int left, int right, int tIdx, int val){
    if(tIdx < left || tIdx > right) {
        return;
    }
    if(left == right){
        seq[idx].second = val;
        arr[left] = val;
        return;
    }

    int mid = (left + right) / 2;

    update(2*idx, left, mid, tIdx, val);
    update(2*idx+1, mid+1, right, tIdx, val);

    seq[idx] = merge(seq[2*idx], seq[2*idx+1]);
}

std::pair<int,int> query(int idx, int lRange, int rRange, int lQuery, int rQuery){
    if(rRange < lQuery || rQuery < lRange) {
        return {2000000000, 2000000000};
    }
    if(lQuery <= lRange && rRange <= rQuery) {
        return seq[idx];
    }

    int mid = (lRange + rRange) / 2;
    
    std::pair<int,int> left = query(2*idx, lRange, mid, lQuery, rQuery);
    std::pair<int,int> right = query(2*idx+1, mid+1, rRange, lQuery, rQuery);

    return merge(left, right); 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++){
        std::cin >> arr[i];
    }

    init(1, 1, n);

    int m;
    std::cin >> m;

    for(int i = 0; i < m; i++){
        int cmd, a, b;
        std::cin >> cmd >> a >> b;

        if(cmd == 1){
            update(1, 1, n, a, b);
        }
        else {
            std::cout << query(1, 1, n, a, b).first << "\n";
        }
    }
}