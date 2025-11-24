#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

std::string cmd[10001];
int arr[10001];
std::queue<int> q;

int main() {
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; i++){
        memset(arr, (1 << 7) - 1, sizeof(arr));
        while(!q.empty()){
            q.pop();
        }

        int st, ed;
        std::cin >> st >> ed;

        cmd[st] = "";
        q.push(st);
        arr[st] = 0;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            int d, s, l, r;
            d = (cur*2) % 10000;
            s = (cur == 0) ? 9999 : cur-1;
            l = (cur % 1000) * 10 + cur / 1000;
            r = (cur / 10) + (cur%10)*1000; 
            //std::cout << d << " " << s << " " << l << " " << r << "\n";
            //int p; std::cin >> p;
            if(arr[d] > arr[cur] + 1){
                arr[d] = arr[cur] + 1;
                cmd[d] = cmd[cur] + "D";
                q.push(d);                
            }
            if(arr[s] > arr[cur] + 1){
                arr[s] = arr[cur] + 1;
                cmd[s] = cmd[cur] + "S";
                q.push(s);
            }
            if(arr[l] > arr[cur] + 1){
                arr[l] = arr[cur] + 1;
                cmd[l] = cmd[cur] + "L";
                q.push(l);
            }
            if(arr[r] > arr[cur] + 1){
                arr[r] = arr[cur] + 1;
                cmd[r] = cmd[cur] + "R";
                q.push(r);
            }
        }
        std::cout << cmd[ed] << "\n";
    }
}