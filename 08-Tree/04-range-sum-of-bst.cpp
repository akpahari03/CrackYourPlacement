/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* root, int low, int high,int& sum) {
        if(root==NULL) return;
        inOrder(root->left,low,high,sum);
        if(root->val>=low && root->val<=high) sum+=root->val;
        inOrder(root->right,low,high,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        inOrder(root,low,high,sum);
        return sum;

    }
};

//using concept of bst
int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        if(root->val < low) return rangeSumBST(root->right,low,high);
        if(root->val > high) return rangeSumBST(root->left,low,high);
        return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }