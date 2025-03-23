class Solution {

    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mapping;
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }
        int preorderIndex;
        preorderIndex = 0;
        return build(preorder, preorderIndex, 0, inorder.size() - 1, mapping);
    }

    TreeNode* build(vector<int>& preorder, int& preorderIndex, int start, int end, unordered_map<int, int> mapping) {
        if (start > end) return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mapping[rootVal];

        root->left = build(preorder, preorderIndex, start, mid - 1, mapping);
        root->right = build(preorder, preorderIndex, mid + 1, end, mapping);

        return root;
    }    
};