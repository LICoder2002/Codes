//https://leetcode.cn/problems/construct-string-from-binary-tree/

/*
给你二叉树的根节点 root ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。
空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
*/

#include<string>
using std::string;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

class Solution {
public:
    void _tree2str(TreeNode* root, string& str) {
        if (root == nullptr)
            return;
        str += std::to_string(root->val);
        if (root->left) {
            str += '(';
            _tree2str(root->left, str);
            str += ')';
        }
        else if (root->right) {
            str += "()";
        }
        if (root->right) {
            str += '(';
            _tree2str(root->right, str);
            str += ')';
        }
    }
    string tree2str(TreeNode* root) {
        string str;
        _tree2str(root, str);
        return str;
    }

};