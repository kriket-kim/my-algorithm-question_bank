#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++){
        q.push(i);    
    }

    while(!q.empty()){
        if(q.size()!=1){
            q.pop();
        }else {
            break;
        }

        if(q.size()!= 1){
            q.push(q.front());
            q.pop();
        }
        else {
            break;
        }
    }

    std::cout << q.front();
}