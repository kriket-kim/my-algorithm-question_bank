#include <iostream>
#include <cmath>

int length, width, height;
int n;
int cnt[20];
int s[20];

long long acc = 0;
int flag = 0;

void fit(int max_size, int length, int width, int height){ 
    //std::cout << "call: " << max_size << " " << length << " " << width << " " << height << "\n"; 
    int cur = -1;
    for(int i = max_size; i >= 0; i--){
        if(cnt[i] && s[i] <= length && s[i] <= width && s[i] <= height){
            cur = s[i];
            cnt[i]--;
            break;
        }
    }
    //cannot fit the box
    if(cur == -1) {
    //    std::cout << "failed\n";
        flag = 1;
        return;
    }
    //std::cout << "cur size: " << cur << "\n";
    acc++;

    int next_size = (cnt[max_size] ? max_size : max_size - 1);
    if(length-cur != 0) fit(next_size, length-cur, width, cur);
    if(width-cur != 0)fit(next_size, cur, width-cur, cur);
    if(height-cur != 0)fit(next_size, length, width, height-cur);     
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> length >> width >> height;
    std::cin >> n;
    
    int t, cnts;
    for(int i = 0; i < n; i++){
        std::cin >> t >> cnts;
        cnt[t] = cnts;
        s[t] = pow(2, t);
    }

    fit(t, length, width, height);
    if(flag) std::cout << "-1\n";
    else std::cout << acc << "\n";
}