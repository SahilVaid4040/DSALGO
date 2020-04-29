#include<iostream>
using namespace std;
class Solution {
public:
    int max_path_sum;
    int maxPathSum(TreeNode* root) {
        max_path_sum = -999999;
        path_sum(root);
        return max_path_sum;
    }
    int path_sum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = max(0,path_sum(root->left));
        int right = max(0,path_sum(root->right));
        max_path_sum = max(max_path_sum, root->val+left+right);
        return max(left,right)+root->val;
    }
};
