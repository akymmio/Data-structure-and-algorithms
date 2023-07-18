#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res = 0, count = 0;
    int averageOfSubtree(TreeNode* root) {
        post(root);
        return res;
    }
    int post(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int c = count; // 当前节点个数
        count++; // 每次遍历一个节点，总的节点数量++，从上往下节点数量++，越往下差值越小，
        int val = post(root->left) + post(root->right) + root->val;
        if (root->val == val / (count - c))
            res++;
        return val;
    }
};

int main() {
    // 构造一棵二叉树
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(12);

    // 计算平均值等于节点值的子树数量
    Solution s;
    int res = s.averageOfSubtree(root);
    std::cout
        << "The number of subtrees with average value equal to node value is: "
        << res << std::endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    system("pause");
    return 0;
}
