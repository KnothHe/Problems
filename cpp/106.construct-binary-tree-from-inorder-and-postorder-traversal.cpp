/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (37.39%)
 * Total Accepted:    136.6K
 * Total Submissions: 365K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return helper(postorder.size()-1, 0, inorder.size()-1, postorder);
    }

private:
    unordered_map<int, int> map;

    TreeNode* helper(int postEnd, int inBeg, int inEnd, vector<int>& postorder) {
        if (postEnd < 0 || inBeg > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int index = map[root->val];
        root->left = helper(postEnd-inEnd+index-1, inBeg, index-1, postorder);
        root->right = helper(postEnd-1, index+1, inEnd, postorder);

        return root;
    }
};
