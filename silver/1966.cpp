#include <iostream>
#include <queue>

std::priority_queue<int> pq;
std::queue<int> q;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;
    for(int dt = 0; dt < t; dt++){
        while(!q.empty()) q.pop();
        while(!pq.empty())pq.pop();

        int n, tidx;
        std::cin >> n >> tidx;
    
        int tmp;
        for(int i = 0; i < n; i++){
            std::cin >> tmp;
            q.push(tmp);
            pq.push(tmp);
        }    
        
        int cnt = 0;

        while(!q.empty()){
            if(q.front() == pq.top()){
                pq.pop();
                q.pop();
                ++cnt;
                if(tidx == 0){
                    std::cout << cnt << "\n";
                    break;
                }
                else {
                    tidx--;
                }
            }
            else {
                q.push(q.front());
                q.pop();
                if(tidx == 0){
                    tidx = q.size()-1;
                }
                else {
                    tidx--;
                }
            }
        }
    }
}