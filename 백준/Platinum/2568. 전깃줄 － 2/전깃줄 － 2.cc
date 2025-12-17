//DP and LIS
//While it looks like it require two sorting,
//on A sorted, it is just finding LIS on Pole B.
//Then finding number of elements is just classical NlogN algorithm for LIS.

//Notes on Backtracing LIS:
/*
    LIS: it contains the smallest ending value of 
    increasing subsequence of all increasing subsequence of length k+1 found so far
    Therefore, in order to print the actual sequence, we need to maintain the longest length
    Hence we use another array, which records where the element was placed. 

    trace[i] = kth element of increasing subsequence when vec[i] was processed

    then on backtrace, we keep the first-occurence from iteration from back.
*/
#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::pair<int,int>> vec;
std::vector<std::pair<int,int>> lis;
std::vector<int> trace;

int binsearch(int left, int right, std::pair<int,int> targ){
    int mid;

    while(left < right){
        mid = (left + right) / 2;
        if(lis[mid].second < targ.second){
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return right;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    lis = std::vector<std::pair<int,int>>(n, {0,0});
    trace = std::vector<int>(n, 0);
    vec.reserve(n);

    for(int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        vec.emplace_back(a,b);
    }
    std::sort(vec.begin(), vec.end());

    int i = 1, j = 0;
    lis[0] = vec[0];
    trace[0] = 0;

    while(i < n) {
        if(lis[j].second < vec[i].second) {
            j += 1;
            lis[j] = vec[i];
            trace[i] = j;
        }
        else {
            int idx = binsearch(0, j, vec[i]);
            lis[idx] = vec[i];
            trace[i] = idx;
        }

        i += 1;
    }
    std::vector<bool> part_of_lis(n, false);
    int targ = j;
    for(int i = n-1; i >= 0; i--){
        if(trace[i] == targ) {
            part_of_lis[i] = true;
            targ--;
        }
    }

    std::cout << n - (j+1) << "\n";
    for(int i = 0; i < n; i++){
        if(!part_of_lis[i]) std::cout << vec[i].first << "\n";
    }
}