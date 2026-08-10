class Solution {
    int leftHeight(TreeNode* root){
        int cnt=0;
        while(root){
            cnt++;
            root=root->left;
        }
        return cnt;
    }
    int rightHeight(TreeNode* root){
        int cnt=0;
        while(root){
            cnt++;
            root=root->right;
        }
        return cnt;
    }
    int cntNode(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = leftHeight(root->left);
        int rh = rightHeight(root->right);

        if (lh == rh)
            return (1 << (lh + 1)) - 1;

        return 1 + cntNode(root->left) + cntNode(root->right);
    }

public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return cntNode(root);
    }
};