#include <iostream>
#include <vector>

int arr[1001], n;
std::vector<int> lis;

int bin_search(int start, int end, int element){
    while(start < end) {
        int mid = ( start + end ) / 2;
        if (element > lis[mid]) start = mid+1;
        else end = mid;
    }
    return end;
}

int main() {
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    int ret = 0;
    //start with first element in sequence
    lis.push_back(arr[0]);

    for(int i = 0; i < n; i++){
        //if next element is larger than 
        //last element of current subsequence, add it
        if(arr[i] > lis.back()){
            lis.push_back(arr[i]);
            ret = lis.size()-1;
        }
        //find where to insert
        int pos = bin_search(0, ret, arr[i]);
        lis[pos] = arr[i];
    }

    std::cout << ret + 1;
}