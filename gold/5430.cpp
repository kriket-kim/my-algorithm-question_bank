#include <iostream>
#include <deque>
#include <string>
#include <sstream>

std::deque<int> dq;
std::string cmd, raw;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int t, n;
    std::cin >> t;

    for(int dt = 0; dt< t; dt++){
        dq.clear();
        std::cin >> cmd;
        std::cin >> n;
        std::cin >> raw;

        std::string raw_nb = raw.substr(1, raw.size()-2);
        
        std::stringstream ss(raw_nb);
        std::string token;
        while(std::getline(ss, token, ',')){
            dq.push_back(std::stoi(token));
        }

        bool dir = true;
        bool flag = true;
        for(int i = 0; i < cmd.size(); i++){
            char cur_cmd = cmd[i];

            if(cur_cmd == 'R') dir = !dir;
            if(cur_cmd == 'D') {
                if(dq.size() == 0) {
                    flag = false;
                    break;
                }
                else if(dir == 1) dq.pop_front();
                else dq.pop_back();
            }
        }
        
        if(flag == false) {
            std::cout << "error\n";
            continue;
        }
        std::cout << "[";
        if(dir) {
            for(int i = 0; i < dq.size(); i++){
                std::cout << dq[i];
                if(i != dq.size() -1) std::cout << ",";
            }
        }else {
            for(int i = dq.size()-1; i >= 0; i--){
                std::cout << dq[i];
                if(i != 0) std::cout << ",";
            }

        }
        std::cout << "]\n";
    }

}