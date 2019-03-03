int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int i, j;
    i = maxDepth(root->left);
    j = maxDepth(root->right);
    return i > j ? i+1 : j+1;
}
