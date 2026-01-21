#include <iostream>
#include <algorithm>
#include <vector>

int n;
std::vector<int> inorder, postorder, position;

void find_preorder(int in_st, int in_ed, int post_st, int post_ed){
    if(in_st >= in_ed || post_st >= post_ed) return;
    //first find the root using postorder
    int root = postorder[post_ed - 1];
    std::cout << root << " ";

    int root_idx = position[root];
    
    int left_size = root_idx - in_st;
    //left = 0 to root_idx
    //std::cout << in_st << " " << root_idx << " " << post_st << " " << post_st + root_idx << "\n";
    find_preorder(in_st, root_idx, post_st, post_st + left_size);
    //right = root_idx to end
    //std::cout << root_idx + 1 << " " << in_ed << " " << post_st + root_idx + 1 << " " << post_ed << "\n";
    find_preorder(root_idx + 1, in_ed, post_st + left_size, post_ed - 1);
}

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;
    
    inorder.resize(n);
    postorder.resize(n);
    position.resize(n + 1);

    for(int i = 0; i < n; i++){
        std::cin >> inorder[i];
        position[inorder[i]] = i;
    }
    for(int i = 0; i < n; i++){
        std::cin >> postorder[i];
    }

    find_preorder(0, n, 0, n);
}